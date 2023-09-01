/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/08/07
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "LineManager.h"

using namespace std;
namespace sdds {
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
   {
      try {
         ifstream filex(file);
         if (filex) {
            while (!filex.eof()) {
               std::string tempHolder1, workSpace, nextWorkSpace;
               std::string::size_type x{};

               std::getline(filex, tempHolder1);

               x = tempHolder1.find('|');

               if (x != std::string::npos) {
                  workSpace = tempHolder1.substr(0, x);
                  nextWorkSpace = tempHolder1.substr(x+1);
               }
               else {
                  workSpace = tempHolder1;
                  nextWorkSpace = "End Of Line";
               }

               copy_if(stations.begin(), stations.end(), back_inserter(m_activeLine), [&](Workstation* ws) {
                  return ws->getItemName() == workSpace;
                  });

               auto it = find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                  return ws->getItemName() == nextWorkSpace;
                  });

               if (it != stations.end()) {
                  m_activeLine.back()->setNextStation(*it);
               }
               else {
                  m_activeLine.back()->setNextStation(nullptr);
               }
            }

            std::vector<Workstation*>::iterator it1;
            std::vector<Workstation*>::iterator it2;

            for (it1 = m_activeLine.begin(); it1 != m_activeLine.end(); it1++) {
               bool found = false;
               for (it2 = m_activeLine.begin(); it2 != m_activeLine.end() && found == false; it2++) {
                  if ((*it2)->getNextStation() != nullptr) {
                     string temp1 = (*it1)->getItemName();
                     string temp2 = (*it2)->getNextStation()->getItemName();

                     if ((*it1)->getItemName() == (*it2)->getNextStation()->getItemName()) {
                        found = true;
                     }
                  }
               }
               if (found == false) {
                  m_firstStation = *it1;
                  break;
               }
 
            }
            m_cntCustomerOrder = g_pending.size();
         }
      }
      catch (...) {
         throw("Error in Constructor");
      }

   }

   void LineManager::reorderStations() {
      std::vector<Workstation*>::iterator it;
      m_activeLine.clear();
      m_activeLine.push_back(m_firstStation);

      while (m_activeLine.back()->getNextStation() != nullptr) {
         m_activeLine.push_back(m_activeLine.back()->getNextStation());
      }
   }

   bool LineManager:: run(std::ostream& os) {
      static int numberOfTimesCalled{};
      numberOfTimesCalled++;

      os << "Line Manager Iteration: " << numberOfTimesCalled << endl;
      if (!g_pending.empty()) {
         *m_firstStation += move(g_pending.front()); // this just added 1st customer order into the m_orders deque now it will move

         g_pending.pop_front();
      }
      
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) { // activeLine contains all the workstations
         ws->fill(os);
         });
      
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
         ws->attemptToMoveOrder(); // har ek workstation de m_order ch aaha order pavana chahnda aa. aaha means 1st customer order from m_orders
         });

      return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;

   }
   void LineManager::display(std::ostream& os) const {
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
         ws->display(os);
         });
   }
}
