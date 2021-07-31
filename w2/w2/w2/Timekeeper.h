//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185
#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// Chris Szalwinski
// 2019/01/11

#include <iostream>
#include <chrono>

namespace sict {
	const int MAX_RECORDS = 10;
	class Timekeeper {
		int nr{ 0 };
		std::chrono::steady_clock::time_point ts;
		std::chrono::steady_clock::time_point te;
		struct {
			const char* msg;
			const char* units;
			std::chrono::steady_clock::duration duration;
		} record[MAX_RECORDS];
	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		void report(std::ostream&) const;
	};
}
#endif
