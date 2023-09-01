/*
* Name - Avni Goyal
* Seneca Email - agoyal31@myseneca.ca
* Seneca Student ID - 166795211
* Date of completion - 2023/08/07
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <string>
#include "Station.h"

namespace sdds {

   class CustomerOrder {

		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};

	public:
		static size_t m_widthField;
		CustomerOrder() = default;
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& custOrd);
		CustomerOrder& operator=(const CustomerOrder& custOrd) = delete;
		CustomerOrder(CustomerOrder&& custOrd)noexcept;
		CustomerOrder& operator=(CustomerOrder&& custOrd)noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

   };
}
#endif // !SDDS_CUSTOMERORDER_H
