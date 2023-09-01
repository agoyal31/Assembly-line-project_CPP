#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/08/07
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <deque>

#include <string>
#include "CustomerOrder.h"

namespace sdds {

  extern std::deque<CustomerOrder>g_pending; // holds the orders to be placed onto the assembly line at the first station.
  extern std::deque<CustomerOrder>g_completed; // holds the orders that have been removed from the last station and have been completely filled
  extern std::deque<CustomerOrder>g_incomplete; // holds the orders that have been removed from the last station and could not be filled completely.

   class Workstation : public Station {
      std::deque<CustomerOrder>m_orders; // These are orders that have been placed on this station to receive service (or already received service).
      Workstation* m_pNextStation; // a pointer to the next Workstation on the assembly line

   public:
      Workstation(const std::string& str) :Station(str) {}; // assume table is in this workstation
      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station = nullptr);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);

      //the object cannot be copied or moved
      Workstation(const Workstation& ws) = delete;
      Workstation& operator=(const Workstation& ws) = delete;
      Workstation(Workstation&& ws) = delete;
      Workstation& operator=(Workstation&& ws) = delete;
   };

}


#endif // !SDDS_WORKSTATION_H
