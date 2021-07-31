//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>
#include <vector>

namespace sict {
	template <class T, int N>
	class List {
		T m_arry[N];
		size_t m_elements;
	public:
		List() : m_arry{}, m_elements{} {}
		size_t size() const {
			return m_elements;
		}

		const T& operator[](size_t i) const {
			return m_arry[i];
		}

		void operator+=(const T& t) {
			if (m_elements <= N) {
				m_arry[m_elements] = t;
				m_elements++;
			}
		}
	};
	template<class T, class L, class V, int N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			V current;
			List<T, N>& temp = (List<T,N>&)*this;
			current = SummableLVPair<L,V>::getInitialValue();
			for (size_t i = 0; i < temp.size(); i++) {

				if (temp[i].getLabel() == label) {
					current = temp[i].sum(label, current);
				}
			}
			return current;
		}
	};
}
#endif // !SICT_LIST_H