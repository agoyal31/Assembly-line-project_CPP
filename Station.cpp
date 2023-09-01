/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/29
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include<iomanip>
#include "Station.h"
//#include <iomanip>
using namespace std;
namespace sdds {
	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;
	Station::Station(const string& str)
	{
		Utilities utility;
		bool continueC = true;
		size_t initialPos = 0;
		m_itemNameHandled = utility.extractToken(str, initialPos, continueC);
		m_serialNumAssignedToItem = stoi(utility.extractToken(str, initialPos, continueC));
		m_numItemsInStock = stoi(utility.extractToken(str, initialPos, continueC));
		if (Station::m_widthField < utility.getFieldWidth()) {
			Station::m_widthField = utility.getFieldWidth();
		}
		m_stationDescription = utility.extractToken(str, initialPos, continueC);
		m_stationID = ++id_generator;
	}

	const string& Station::getItemName() const
	{
		return m_itemNameHandled;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_serialNumAssignedToItem++;
	}

	size_t Station::getQuantity() const
	{
		return m_numItemsInStock;
	}

	void Station::updateQuantity()
	{
		if (m_numItemsInStock > 0) {
			--m_numItemsInStock;
		}
	}

	void Station::display(ostream& os, bool full) const
	{
		os << right << setfill('0') << setw(3)  << m_stationID << " | " << left << setfill(' ') << setw(m_widthField) << m_itemNameHandled << " | "
			<< right << setfill('0') << setw(6) << m_serialNumAssignedToItem << " | ";

		if (full) {
			os << setfill(' ') << setw(4) << m_numItemsInStock << " | " << m_stationDescription;
		}
		os << endl;
	}
} 