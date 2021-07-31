//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#pragma once
#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
#include<iostream>
#include<string>

namespace sict {

	template<typename K, typename V>
	class KVPair {
		K m_key;
		V m_value;
	public:
		KVPair() { 
			this->m_key = K();
			this->m_value = V(); 
		};
		KVPair(const K& i, const V& j) { 
			m_key = i;
			m_value = j; 
		};
		template<typename F>
		void display(std::ostream& os, F f)const {
			K temp = K();
			if (this->m_key != temp){
				os << std::left << std::setw(10) << m_key << " : " 
					<< std::right << std::setw(10) << m_value + 5 
					<< std::setw(10) << f(m_value) << std::endl;
			}
		}
	};
}

#endif // !SICT_KVPAIR_H

