//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#pragma once
#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict {

	class Taxable {
		float m_tax;
	public:
		Taxable(float in) {
			m_tax = in; 
		};

		float operator()(float in) {
			return in * (1 + m_tax); 
		};
	};
}

#endif // !SICT_TAXABLE_H

