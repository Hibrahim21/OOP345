//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#include <iostream>
#include <string>
#include "Message.h"

namespace sict {
	Message::Message() {
		m_message.clear();
		m_user.clear();
		m_reply.clear();
		/*m_status = false;
		m_position = 0;*/
	}
	Message::Message(const std::string& str) {
		std::string atChar = "@", space = " ";

		if (str.empty() || (str.find(space) == std::string::npos)) {
			*this = Message();
		}
		else {
			if (str.find(atChar) != std::string::npos) {
				m_user = str;
				m_user.erase(m_user.find(space), m_user.length());

				m_reply = str;
				m_reply.erase(0, 2 + m_reply.find(space));
				m_reply.erase(m_reply.find(space), m_reply.length());

				m_message = str;
				m_message.erase(0, m_message.find(atChar));
				m_message.erase(0, m_message.find(space));

			}
			else {
				m_user = str;
				m_user.erase(m_user.find(space), m_user.length());

				m_message = str;
				m_message.erase(0, m_message.find(space));

			}
		}

		/*if (m_user.size() > 0 || m_user.size() != m_message.size()) {
					m_position = str.find(atChar);
			if (m_position == std::string::npos) {
				m_position = str.find(space);
				m_user = str.substr(0, str.find(space));
			}
			else {
				m_user = str.substr(0, m_position);
			}
			i = str.find(space, m_position);
			idx = i - m_position;
			if (idx != 0) {
				m_reply = str.substr(m_position + 1, idx - 1);
				m_status = true;
			}
			m_message = str.substr(i + 1);
		}*/
	}
	bool Message::empty() const {
		if (m_message.size() == 0) return true;
		else return false;
	}
	void Message::display(std::ostream & os) const {
		if (this->empty() != true) {
			os << ">User  : " << m_user << std::endl;
			if (m_reply.size() > 0) {
				os << " Reply : " << m_reply << std::endl;
			}
			os << " Tweet : " << m_message << std::endl;
		}
	}
}