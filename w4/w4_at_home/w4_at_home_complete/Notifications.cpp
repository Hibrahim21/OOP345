//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#include <iostream>
#include <string>
#include "Notifications.h"

namespace sict {
	Notifications::Notifications(){
		message = nullptr;
		m_elements = 0;
		m_maxEle = 0;
	}

	Notifications::~Notifications(){		
		delete[] message;
 		message = nullptr;
	}

	Notifications::Notifications(const Notifications& src)	{
		message = nullptr;
		*this = src;
	}

	Notifications& Notifications::operator=(const Notifications& src){
		if (this != &src) {
			m_elements = src.m_elements;
			m_maxEle = src.m_maxEle;
			delete[] message;
			if (src.message != nullptr) {
				message = new const Message * [m_elements];
				for (int i = 0; i < m_elements; i++) {
					message[i] = src.message[i];
				}
			}
			else {
				message = nullptr;
			}
		}
		return *this;
	}

	Notifications::Notifications( Notifications&& src) {
		message = nullptr;
		*this = std::move(src);
	}

	Notifications& Notifications::operator=(Notifications&& src) {
		
		if (this != &src) {
			
			delete[]message;
			message = src.message;
			m_elements = src.m_elements;
			m_maxEle = src.m_maxEle;
			src.message = nullptr;
			src.m_elements = 0;
			src.m_maxEle = 0;
		}
		return *this;
	}

	Notifications::Notifications(int ele){
		if (ele >= 0) {
			m_maxEle = ele;
			m_elements = 0;
			message = new const Message*[ele];
			for (int i = 0; i < m_maxEle; i++) {
				message[i] = nullptr;
			}
		}
		else {
			new (this) Notifications();
		}
	}

	Notifications& Notifications::operator+=(const Message& msg){
		if (m_elements < m_maxEle && !msg.empty()) {
			message[m_elements++] = &msg;
		}
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msg){
		int indexHolder = 0;
		bool TF = true;
		for (int i = 0; i < m_elements && TF; i++) {
			if (message[i] == &msg) {
				message[i] = nullptr;
				TF = false;
				indexHolder = i;
			}
		}
		if (!TF) {
			for (int cnt = indexHolder; cnt < m_elements - 1; cnt++) {
				message[cnt] = message[cnt + 1];
				message[cnt + 1] = nullptr;
				
			}
			m_elements--;

		}
		return *this;
	}

	void Notifications::display(std::ostream& os) const{
		for (int cnt = 0; cnt < m_elements; cnt++) {
			(*message[cnt]).display(os);
		};
	}

	size_t Notifications::size() const{
		return m_elements;
	}

	std::ostream& operator<<(std::ostream& os, Notifications& idk){
		idk.display(os);
		return os;
	}
}

