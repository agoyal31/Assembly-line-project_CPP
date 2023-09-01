/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/08/07
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include "Workstation.h"

namespace sdds {

   std::deque<CustomerOrder>g_pending; // holds the orders to be placed onto the assembly line at the first station.
   std::deque<CustomerOrder>g_completed; // holds the orders that have been removed from the last station and have been completely filled
   std::deque<CustomerOrder>g_incomplete; // holds the orders that have been removed from the last station and could not be filled completely.



   void Workstation::fill(std::ostream& os)
   {
      if (!m_orders.empty()) {
         m_orders.front().fillItem(*this, os);
      }
   }

   bool Workstation::attemptToMoveOrder() {
      if (!m_orders.empty()) {
            if (m_orders.front().isItemFilled(this->getItemName()) || this->getQuantity() <= 0) {
               if (m_pNextStation != nullptr) {
                  *m_pNextStation += std::move(m_orders.front());

               }
               else {
                  if (m_orders.front().isOrderFilled()) {
                     g_completed.push_back(std::move(m_orders.front()));
                  }
                  else {
                     g_incomplete.push_back(std::move(m_orders.front()));
                  }
               }
               m_orders.pop_front();  //removes the first element from the queue
               return true;
            }
         //}
      }
      return false;
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }

   void Workstation::setNextStation(Workstation* station) {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const {
      if (m_pNextStation != nullptr) {
         os << this->getItemName() << " --> " << this->getNextStation()->getItemName() << std::endl;
      }
      else {
         os << this->getItemName() << " --> " << "End of Line" << std::endl;
      }

   }

}