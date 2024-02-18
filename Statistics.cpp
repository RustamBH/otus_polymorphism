// Statistics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IStatistics.h"
#include "Min.h"
#include "Max.h"
#include "StdDev.h"


int main() {

	const size_t statistics_count = 4;
	IStatistics* statistics[statistics_count];

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new StdDev{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		// Take a start time
		auto start_time = std::chrono::system_clock::now();
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
		// Take an end time
		auto end_time = std::chrono::system_clock::now();
		// Calculate a duration
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
		std::cout << statistics[i]->name() << " duration = " << microseconds.count() << " mcs" << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}
