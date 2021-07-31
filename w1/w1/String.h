// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.h
//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#ifndef SICT_STRING_H
#define SICT_STRING_H

const int MAX = 3;

namespace sict {
	class String {
		char *m_string;
	public:
		String();
		String(const char*);
		void display(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream&, const String&);
}
#endif // !SICT_STRING_H