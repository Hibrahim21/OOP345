#include <fstream>
#include <iomanip>
#include <string>
#include "Sale.h"
#include "Product.h"

extern int FW;

namespace sict{

	Sale::Sale(const char* file){

		std::ifstream f(file, std::ios::in);
		if (!f.is_open()) {
			throw "file could not open"; 
		}
		else {
			f.seekg(0, std::ios::beg);
			bool read = true;

			do {
				iProduct* temp = readRecord(f);
				if (temp)
					products.push_back(temp);
				else
					read = false;

			} while (read);
		}
		f.close();
	}

	void Sale::display(std::ostream& os) const
	{
		os << "\nProduct No" << std::setw(FW) << "Cost" << ' ' << "Taxable" << std::endl;
		double total = 0.0;
		for (unsigned i = 0; i < products.size(); i++) {
			total += products[i]->price();
			products[i]->display(os);
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;
	}
}