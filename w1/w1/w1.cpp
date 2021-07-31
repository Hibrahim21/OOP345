// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185

#include <iostream>
#include "process.h"
extern const int INITIAL = 3;

using namespace sict;

int main(int argc, char *argv[]) {
	int returnType = 0;
	std::cout << "Command Line : ";
	for (int cnt = 0; cnt < argc; cnt++) {
		std::cout << argv[cnt];
	}
	std::cout << std::endl;
	if (argc <= 1) {
		std::cout << "***Insufficient number of arguments***";
		returnType = 1;
	}
	else {
		for (int i = 1; i < argc; i++) {
			sict::process(argv[i]);
		}
		returnType = 0;
	}
	return returnType;
}