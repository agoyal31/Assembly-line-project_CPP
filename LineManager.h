/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/08/07
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include "Workstation.h"

namespace sdds {
   class LineManager {
      std::vector<Workstation*> m_activeLine{}; // these pointers are pointing to the -> const std::vector<Workstation*>& stations)
      size_t m_cntCustomerOrder{};
      Workstation* m_firstStation{}; // it will be pointing to the 1st station object of the m_activeLine vector which will be pointing to the stations

   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      void reorderStations();
      bool run(std::ostream& os);
      void display(std::ostream& os) const;
   };
}
#endif // !SDDS_LINEMANAGER_H
