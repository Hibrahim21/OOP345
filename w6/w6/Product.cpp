#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Product.h"

extern int FW;

namespace sict{
	
	Product::Product(): productNum{ 0 } , cost{ 0.0 } {}
	
	Product::Product(int productNumber, double cost) : productNum{ productNumber } , cost{ cost } {}
	
	double Product::price() const{
		return cost;
	}

	void Product::display(std::ostream& os) const{
		if(Stattype) {
			os << std::right << std::setw(FW) << productNum << std::setw(FW) << std::fixed << std::setprecision(2) << cost << std::endl;
		}
		else {
			os << std::right << std::setw(FW) << productNum << std::setw(FW) << std::fixed << std::setprecision(2) << cost;
		}
	}

	void Product::type(){
		Stattype = false;
	}

	iProduct* readRecord(std::ifstream& file){
	
		iProduct* temp = nullptr;
		int product_number = 0;
		double costs = 0;
		char tax = '\0';
		file >> product_number >> costs;

		if (file.good()) {
			if (file.get() != '\n') {
				file.get(tax);
				temp = new TaxableProduct(product_number, costs, tax);
			}
			else {
				temp = new Product(product_number, costs);
			}
			return temp;
		}
	}
	
	std::ostream& operator<<(std::ostream& os, const iProduct& p){
		p.display(os);
		return os;
	}

	TaxableProduct::TaxableProduct(int num, double cost, char taxt_stat) : Product(num, cost){
		Product::type();
		switch (taxt_stat) {
		case 'H':
			taxType = TaxableProduct::Tax::HST;
			rate = 0.13;
			break;
		case 'P':
			taxType = TaxableProduct::Tax::PST;
			rate = 0.08;
			break;
		}
	}

	double TaxableProduct::price() const{
		return Product::price()* (1 + rate);
	}

	void TaxableProduct::display(std::ostream & os) const{
		
		Product::display(os);
		if (taxType == Tax::HST)
			os << " HST";
		else if (taxType == Tax::PST) {
			os << " PST";
		}
		os << std::endl;
	}
}