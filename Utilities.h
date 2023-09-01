/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/07/29
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H
namespace sdds {
	class Utilities {
		size_t m_widthField = 1;
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}

#endif