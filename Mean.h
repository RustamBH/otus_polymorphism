#pragma once

#include "IStatistics.h"


class Mean : public IStatistics {
public:
	Mean() {}
	Mean(std::vector<double> v) : m_vec{ v } {}

	void update(double next) override {
		m_vec.push_back(next);
	}

	double eval() const override {
		return std::accumulate(m_vec.begin(), m_vec.end(), 0.0) / m_vec.size();
	}

	const char* name() const override {
		return "mean";
	}

private:
	std::vector<double> m_vec;
};
