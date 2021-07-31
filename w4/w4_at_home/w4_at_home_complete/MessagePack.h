//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include <string>
#include "Message.h"

namespace sict {
	class MessagePack {
		Message* message;
		size_t m_elements;
	public:
		MessagePack();// COMPLETE
		~MessagePack();// COMPLETE
		MessagePack(const MessagePack&);// COMPLETE
		MessagePack& operator=(const MessagePack&);// COMPLETE
		MessagePack(MessagePack&&) ;// COMPLETE
		MessagePack& operator=(MessagePack&&);// COMPLETE
		MessagePack(Message**, size_t);// COMPLETE
		void display(std::ostream& os) const;// COMPLETE
		size_t size() const;// COMPLETE
	};
	std::ostream& operator<<(std::ostream&, MessagePack&);
}


#endif // !SICT_MESSAGEPACK_H