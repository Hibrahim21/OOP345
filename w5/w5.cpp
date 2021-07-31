// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}

int main(int argc, char* argv[]) {
	try
	{
		std::cout << "Command Line : ";
		for (int i = 0; i < argc; i++) {
			std::cout << argv[i] << ' ';
		}
		std::cout << std::endl;
		// check for command line errors
		if (argc != 3) exit(1);

		// set for fixed, 2-decimal point output
		std::cout << std::fixed << std::setprecision(2);

		// process price list file
		KVList<KVPair<std::string, float>> priceList = createList<KVList<KVPair<std::string, float>>, KVPair<std::string, float>, std::string, float>(argv[1]);
		std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
		std::cout << "Description:      Price Price+Tax\n";
		priceList.display(std::cout, Taxable(HST));


















		
		
		// check for command line errors
		if (argc != 3) exit(1);

		// set for fixed, 2-decimal point output
		std::cout << std::fixed << std::setprecision(2);

		// process price list file
		KVList<KVPair<int, float>> GreadeList = createList<KVList<KVPair<int, float>>, KVPair<int, float>, int, float>(argv[2]);
		std::cout << "\nStudent List Letter Grades Included\n==================================\n";
		std::cout << "Student No :      Grade    Letter\n";
		GreadeList.display(std::cout, [](float i) {
			std::string score;
			score.clear();
			if (i <= 49) {
				score = "F";
			}
			else if (i >= 50 && i <= 54) {
				score = "D";
			}
			else if (i >= 55 && i <= 59) {
				score = "D+";
			}
			else if (i >= 60 && i <= 64) {
				score = "C";
			}
			else if (i >= 65 && i <= 69) {
				score = "C+";
			}
			else if (i >= 70 && i <= 74) {
				score = "B";
			}
			else if (i >= 75 && i <= 79) {
				score = "B+";
			}
			else if (i >= 80 && i <= 89) {
				score = "A";
			}
			else if (i >= 90) {
				score = "A+";
			};
			return score;
	
		});

	}
	catch (const std::string err)
	{


		std::string error[2]{ "" };
		error[0] = { "out of bond" };
		error[1] = {"negative size"};


		if (err == error[0]) {
			std::cout << "out of bond" << std::endl;
			exit(3);
		}
		if (err == error[1]) {
			std::cout << "negative size" << std::endl;
			exit(3);
		}

	}


	
}