//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>
#include <vector>

namespace sict {
	template <typename T, int N>
	class List {
		T arry[N];
		size_t m_elements;
	public:
		List() : arry{}, m_elements{} {}
		size_t size() const {
			return m_elements;
		}

		const T& operator[](size_t i) const {
			return arry[i];
		}

		void operator+=(const T& t) {
			if (m_elements <= N) {
				arry[m_elements] = t;
				m_elements++;
			}
		}
	};
}
#endif // !SICT_LIST_H