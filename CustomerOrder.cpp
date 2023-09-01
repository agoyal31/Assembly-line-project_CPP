/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/29
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;
namespace sdds {

   size_t CustomerOrder::m_widthField = {};

   CustomerOrder::CustomerOrder(const std::string& str)
   {
      size_t nextPos{};
      bool toContinue = true;
      Utilities ut;
      m_name = ut.extractToken(str, nextPos, toContinue);
      m_product = ut.extractToken(str, nextPos, toContinue);
      
      //Count character occurrences in a string in C++: https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string-in-c
      m_cntItem = std::count(str.begin(), str.end(), ut.getDelimiter()) - 1;
      m_lstItem = new Item * [m_cntItem];  //DMA
      int i = 0;
      while (toContinue) {
         m_lstItem[i] = new Item(ut.extractToken(str, nextPos, toContinue)); //DMA
         i++;
      }
      if (m_widthField < ut.getFieldWidth())
         m_widthField = ut.getFieldWidth();

  


   }

   CustomerOrder::CustomerOrder(const CustomerOrder& custOrd)
   {
      throw "err";
   }

   CustomerOrder::CustomerOrder(CustomerOrder&& custOrd)noexcept
   {
      *this = move(custOrd);
   }

   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& custOrd)noexcept
   {
      if (this != &custOrd) {
         // delete prev memory of this
         for (size_t i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i] != nullptr) {
               delete m_lstItem[i];
            }
         }
         delete[] m_lstItem;

         m_cntItem = custOrd.m_cntItem;
         m_name = custOrd.m_name;
         m_product = custOrd.m_product;
         m_lstItem = custOrd.m_lstItem;

         custOrd.m_lstItem = nullptr;
         custOrd.m_cntItem = 0;

      }
      return *this;
   }

   CustomerOrder::~CustomerOrder()
   {
      for (size_t i = 0; i < m_cntItem; i++) {
         delete m_lstItem[i];
      }
      delete[] m_lstItem;
   }

   bool CustomerOrder::isOrderFilled() const
   {
      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_isFilled == false) {
            return false;
         }
      }
      return true;
   }

   bool CustomerOrder::isItemFilled(const std::string& itemName) const
   {
      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == itemName) {
            if (!m_lstItem[i]->m_isFilled) {
               return false;
            }
         }
      }
      return true;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os)
   {
      for (size_t i = 0; i < m_cntItem; i++) {
         if (station.getItemName() == m_lstItem[i]->m_itemName) {
            if (station.getQuantity() >= 1 && /*isItemFilled(station.getItemName()) == false*/ !m_lstItem[i]->m_isFilled) {
               m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
               station.updateQuantity();
                  m_lstItem[i]->m_isFilled = true;

               cout << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
               break;
            }
            if (station.getQuantity() < 1) {
               cout << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
         }
      }
   }

   void CustomerOrder::display(std::ostream& os) const {
      os << m_name << " - " << m_product << endl;
      for (size_t i = 0; i < m_cntItem; i++) {
         os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] " << left << setw(m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName << " - ";
         if (m_lstItem[i]->m_isFilled) os << "FILLED" << endl;
         else os << "TO BE FILLED" << endl;
      }
   }





}