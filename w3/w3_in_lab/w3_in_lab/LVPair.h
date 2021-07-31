//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include <iostream>

namespace sict {
	template <class L, class V>
	class LVPair {
		L m_lable;
		V m_value;
	public:
		LVPair() {};
		LVPair(const L& l, const V& v) : m_lable{ l }, m_value{ v } {}
		void display(std::ostream& os) const {
			os << m_lable << " : " << m_value << std::endl;
		}
	};
	template <class L, class V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
}
#endif // !SICT_LVPAIR_H