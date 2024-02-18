#pragma once

#include "IStatistics.h"
#include "Mean.h"


class StdDev : public IStatistics {
public:
	StdDev() : diff_sum{ 0 } {}

	void update(double next) override {
		m_vec.push_back(next);
	}

	double eval() const override {
		Mean mean{ m_vec };
		double m = mean.eval();		
		for (auto it = m_vec.begin(); it != m_vec.end(); ++it)
			diff_sum += ((*it - m) * (*it - m));

		return sqrt(diff_sum / m_vec.size());
	}

	const char* name() const override {
		return "std";
	}

private:
	std::vector<double> m_vec;
	mutable double diff_sum;	
};
