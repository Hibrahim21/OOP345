//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#pragma once
#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H
#include<iostream>

namespace sict {

	template<typename T>
	class KVList {
		T* m_KVList;
		size_t m_length;
		size_t m_quantity;
	public:
		KVList() { 
			m_KVList = nullptr;
			m_length = 0;
			m_quantity = 0; 
		};

		KVList(int i) {
			if (i < 0) {
				m_KVList = nullptr; m_length = 0; m_quantity = 0;
				throw std::string("negative size");

			}
			else{
				m_KVList = new T[i];
				m_length = i;
				m_quantity = 0;

			}
		};

		~KVList() {
			delete[]m_KVList;
			m_KVList = nullptr;
		}

		KVList(KVList&& in)noexcept {
			if (this != &in) {
				m_length = in.m_length;
				m_quantity = in.m_quantity;

				m_KVList = in.m_KVList;

				in.m_KVList = nullptr;
				in.m_quantity = 0;
				in.m_length = 0;
			}
		}

		const T& operator[](size_t i) const {
			if (i > m_quantity) { 
				throw  "out of bond"; 
			}
			else{
				return m_KVList[i];
			}
		}

		template<typename F>
		void display(std::ostream& os, F f)const {

			for (size_t i = 0; i < m_quantity; i++){
				m_KVList[i].display(os, f);
			}

		}

		void push_back(const T& t) {

			if (m_quantity < m_length) {
				m_KVList[m_quantity] = t;
				m_quantity++;
			}
		}
	};
}

#endif // !SICT_KVLIST_H

