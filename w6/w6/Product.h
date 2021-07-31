#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include "iProduct.h"

namespace sict{
	class Product : public iProduct{
		int productNum;
		double cost;
		bool Stattype = true;
	public:
		Product();
		explicit Product(int, double);
		double price() const;
		void display(std::ostream& os) const;
		void type();
	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	
	class TaxableProduct : public Product{
	public:
		TaxableProduct(int, double, char);
		double price() const;
		void display(std::ostream&) const;
		enum class Tax { HST, PST };
	private:
		double rate;
		Tax taxType;
	};
}
#endif // !SICT_PRODUCT_H

