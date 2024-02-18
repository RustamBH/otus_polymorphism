#pragma once

#include <limits>
#include <chrono>
#include <numeric>
#include <vector>


class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char* name() const = 0;
};
