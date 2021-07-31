// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.cpp
//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#include <iostream>
#include <cstring>
#include "String.h"

#define _CRT_SECURE_NO_WARNINGS
extern const int INITIAL;

namespace sict {
	String::String() {
		m_string[0] = '\0';
	}

	String::String(const char* idk){
		if (idk[0] == '\0' || idk == nullptr) {
			String();
		}
		else {
			m_string = new char[std::strlen(idk)];
			for (size_t i = 0; i < std::strlen(idk); i++) {
				m_string[i] = idk[i];
				m_string[std::strlen(idk)] = '\0';
			}
			
		}
	}

	void String::display(std::ostream& idk) const{
		idk << m_string;
	}

	std::ostream& operator<<(std::ostream& os, const String& idk){
		static int counter = INITIAL;
		os << counter++ << ": ";
		idk.display(os);
		return os;
	}
}