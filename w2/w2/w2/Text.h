//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <iostream>

namespace sict {

	class Text {
		size_t counter;
		std::string* StringC;
	public:
		Text();
		Text(char*);
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;
	};
}
#endif // !SICT_TEXT_H