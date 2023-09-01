/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/29
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SDDS_STATION_H
#define _SDDS_STATION_H
#include"Utilities.h"
#include<string>
namespace sdds {
	class Station {
		int m_stationID{};
		std::string m_itemNameHandled{};
		std::string m_stationDescription{};
		unsigned int m_serialNumAssignedToItem{};
		unsigned int m_numItemsInStock{};
	public:
		static size_t m_widthField;
		static int id_generator;
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}

#endif
