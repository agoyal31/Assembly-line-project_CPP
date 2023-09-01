/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/29
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include<iostream>
#include"Utilities.h"
#include<functional>
#include<string>
using namespace std;
namespace sdds {
	char Utilities::m_delimiter = {};

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string::size_type init{};
		string tempStoreString;
		init = str.find(m_delimiter, next_pos);
		if (init - next_pos <= 1) {
			more = false;
			throw("Exception found!");
		}
		else if (init == string::npos) {
			tempStoreString = str.substr(next_pos);
			tempStoreString.erase(tempStoreString.begin(), find_if(tempStoreString.begin(), tempStoreString.end(), bind1st(not_equal_to<char>(), ' ')));
			tempStoreString.erase(std::find_if(tempStoreString.rbegin(), tempStoreString.rend(), bind1st(not_equal_to<char>(), ' ')).base(), tempStoreString.end());
			more = false;
		}
		else {
			tempStoreString = str.substr(next_pos, (init - next_pos));
			tempStoreString.erase(tempStoreString.begin(), find_if(tempStoreString.begin(), tempStoreString.end(), bind1st(not_equal_to<char>(), ' ')));
			tempStoreString.erase(std::find_if(tempStoreString.rbegin(), tempStoreString.rend(), bind1st(not_equal_to<char>(), ' ')).base(), tempStoreString.end());
			next_pos = ++init;
			more = true;
		}
		if (m_widthField < static_cast<size_t>(tempStoreString.length())) {
			m_widthField = static_cast<size_t>(tempStoreString.length());
		}
		return tempStoreString;

	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}