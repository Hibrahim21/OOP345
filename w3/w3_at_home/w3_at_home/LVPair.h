//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include <iostream>
#include <string>
namespace sict {
	template <typename L, typename V>
	class LVPair {
		L m_lable;
		V m_value;
	public:
		LVPair() {};
		LVPair(const L& l, const V& v) : m_lable{ l }, m_value{ v } {}
		V getValue() const { return m_value; }
		L getLabel() const { return m_lable; }
		virtual void display(std::ostream& os) const {
			os << m_lable << " : " << m_value << std::endl;
		}
	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		//static L m_label;
		static V m_initial;
		static size_t m_min;
	public:
		SummableLVPair() {};
		SummableLVPair(const L& label, const V& v):LVPair<L,V>(label,v) {
			if (m_min < label.size()) {
				m_min = label.size();
			};
		}
		static const V& getInitialValue() { return m_initial; }
		V sum(const L& label, const V& sum) const {
			return (sum + LVPair<L, V>::getValue());
		}
		void display(std::ostream& os) const {
			os << std::left << std::setw(m_min);
			LVPair<L, V>::display(os);
		};
	};

	template<typename L, typename V>
	size_t SummableLVPair<L, V>::m_min{0};

	template<>
	int SummableLVPair<std::string, int>::m_initial{ 0 };

	template<>
	std::string SummableLVPair<std::string, std::string>::m_initial{ "" };
	
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& l, const std::string& s) const {
		return (s + " " + LVPair<std::string, std::string>::getValue());
	}
}
#endif // !SICT_LVPAIR_H