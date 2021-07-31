//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Text.h"

namespace sict {

	Text::Text() : counter(0), StringC(nullptr) {}

	Text::Text(char* file){
		std::ifstream f;
		std::string line = {};
		f.open("gutenberg_shakespeare.txt");
		if (f.is_open()){
			while (getline(f, line)) {
				counter++;
			}
		}

		StringC = new std::string[counter];
		std::string lines = {};
		while (getline(f, lines)) {
			StringC[counter] = lines;
		}
		f.close();
	}
	//Copy Constructor
	Text::Text(const Text& idk) {
		StringC = nullptr;
		*this = idk;
	}
	//Copy Assignment Operator
	Text& Text::operator=(const Text& idk){
		if (this != &idk) {
			counter = idk.counter;
			delete[] StringC;
			if (idk.StringC != nullptr) {
				StringC = new std::string[counter];
				for (size_t cnt = 0; cnt < counter; cnt++) {
					StringC[cnt] = idk.StringC[cnt];
				}
			}
			else {
				StringC = nullptr;
			}
		}
		return *this;
	}
	//Move Constructor
	Text::Text(Text&& src){
		*this = std::move(src);
	}
	//Move Assignment OPerator
	Text& Text::operator=(Text&& src){
		if (this != &src) {
			StringC = nullptr;
			delete[] StringC;
			counter = src.counter;
			src.StringC = nullptr;
			src.counter = 0;
		}
		return *this;
	}

	Text::~Text() {
		if (StringC != nullptr) {
			delete[]StringC;
			StringC = nullptr;
		}
	}

	size_t Text::size() const {
		return counter;
	}

}