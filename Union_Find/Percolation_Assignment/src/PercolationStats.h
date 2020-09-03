#ifndef _PERCOLATIONSTATS_
#define _PERCOLATIONSTATS_
#include "Percolation.h"
#include "Union_Find_QU.h"
#include <math.h>

class PercolationStats{
	
	private:
		//stores the percolation threshold for each experiment
		double *thresholds;
		int num_experiments;
	public:
		//constructer, perform independant trials on n-by-n grids
		PercolationStats(int n, int trials);

		//sample mean of percolation threshold
		double mean();

		//sample standard deviation of percolation threshold
		double stddev();

		//low endpoint of 95% confidence interval
		double confidenceLo();

		//high endpoint of 95% confidence interval
		double confidenceHi();

};

#endif
