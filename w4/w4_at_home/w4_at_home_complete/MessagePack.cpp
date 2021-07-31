//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#include <iostream>
#include <string>
#include "MessagePack.h"

namespace sict {
	MessagePack::MessagePack(){
		message = nullptr;
		m_elements = 0;
	}

	MessagePack::~MessagePack(){
		//if (message != nullptr) {
			delete[] message;
			message = nullptr;
		//}
	}

	MessagePack::MessagePack(const MessagePack& src){
		message = nullptr;
		*this = src;
	}

	MessagePack& MessagePack::operator=(const MessagePack& src){
		if (this != &src) {
			delete[] message;
			m_elements = src.m_elements;
			if (src.message != nullptr) {
				message = new Message[m_elements];
				for (size_t i = 0; i < m_elements; i++) {
					message[i] = src.message[i];
				}
			}
			else {
				message = nullptr;
			}
		}
		return *this;
	}

	MessagePack::MessagePack(MessagePack&& idk) {
		message = nullptr;
		*this = std::move(idk);
	}

	MessagePack& MessagePack::operator=(MessagePack&& idk) {
		if (this != &idk) {
			delete[] message;
			m_elements = idk.m_elements;
			message = idk.message;
			idk.message = nullptr;
			idk.m_elements = 0;
		}
		return *this;
	}

	MessagePack::MessagePack(Message** idk, size_t elements){
		if (elements >= 0 && idk != nullptr) {
			message = nullptr;
			m_elements = 0;
			
			for (size_t cnt = 0; cnt < elements; cnt++) {
				if (!idk[cnt]->empty()) {
					m_elements++;
				}
			}
				message = new Message[m_elements]; 
				
				size_t temp = 0;
				for (size_t i = 0; i < elements; i++) {
					if (!idk[i]->empty()) {
						
						message[temp++] = *idk[i]; 
						
					}
				}

		}
		else {
			new (this) MessagePack();
		}
		
	}

	void MessagePack::display(std::ostream& os) const{
		for (size_t cnt = 0; cnt < m_elements; cnt++) {
			message[cnt].display(os); 
		};
	}

	size_t MessagePack::size() const{
		return this->m_elements;
	}

	std::ostream& operator<<(std::ostream& os, MessagePack& idk){
		idk.display(os);
		return os;
	}

}