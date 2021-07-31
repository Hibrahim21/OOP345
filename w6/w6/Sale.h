#ifndef SICT_SALE_H
#define SICT_SALE_H

#include <vector>
#include "Product.h"

namespace sict{

	class Sale{
		std::vector<iProduct*> products;
	public:
		Sale(const char*);
		void display(std::ostream& os) const;
	};
}
#endif // !SICT_SALE_H