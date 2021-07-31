//Name: Hamza Ibrahim 
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185
// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// Chris Szalwinski
// 2019/01/10

#include <iomanip>
#include "Timekeeper.h"

namespace sict {

	// constructor
	//
	Timekeeper::Timekeeper() {}

	// start timer
	//
	void Timekeeper::start() {
		ts = std::chrono::steady_clock::now();
	}

	// stop timer
	//
	void Timekeeper::stop() {
		te = std::chrono::steady_clock::now();
	}

	// record an event
	//
	void Timekeeper::recordEvent(const char* msg) {
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(te - ts);
		if (nr < MAX_RECORDS) {
			this->record[nr].msg = msg;
			this->record[nr].units = " seconds";
			this->record[nr].duration = ms;
			nr++;
		}
	}

	// report the set of times recorded
	// 
	void Timekeeper::report(std::ostream& os) const {
		os << "\nExecution Times:\n";
		for (int i = 0; i < nr; i++)
			os << record[i].msg << ' ' << std::setw(5)
			<< record[i].duration.count() / 1000000
			<< record[i].units
			<< std::endl;
	}
}