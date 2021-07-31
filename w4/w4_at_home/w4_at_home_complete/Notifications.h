//Name: Hamza Ibrahim
//Student ID: 107467185
//Student email: hibrahim21@myseneca.ca

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <string>
#include "Message.h"

namespace sict {
	class Notifications {
		const Message** message;
		int m_maxEle;
		int m_elements;
	public:
		Notifications();
		~Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications( Notifications&&) ;
		Notifications& operator=(Notifications&&);
		Notifications(int);
		Notifications& operator+=(const Message&);
		Notifications& operator-=(const Message&);
		void display(std::ostream&) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream&, Notifications&);
}


#endif // !SICT_NOTIFICATIONS_H