//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <string>

namespace sict {
	class Message {
		std::string m_message;
		std::string m_user;
		std::string m_reply;
		/*std::string m_responder;
		bool m_status;
		size_t m_position;*/
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}


#endif // !SICT_MESSAGE_H