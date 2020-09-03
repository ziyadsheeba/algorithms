#include "Percolation.h"
#include "Union_Find_WQU.h"
#include "PercolationStats.h"
#include <random>
#include <iostream>
#include <math.h>

using namespace std;
int main(){
	int grid_dim;
	int trials;
	cout << "Choose the grid dimension for the Monte Carlo simulation" << endl;
	cin >> grid_dim;
	cout << "Choose the number of trials for the Monte Carlo simulation" << endl;
	cin >> trials;
	PercolationStats percstats(grid_dim, trials);
	cout << "Mean value for perculation threshold: " << percstats.mean() << endl;
	cout << "Standard Deviation value for perculation threshold: " << percstats.stddev() << endl;
	cout << "Lower Bound value for the confidence interval: " <<  percstats.confidenceLo() << endl;
	cout << "Upper Bound value for the confidence interval: " <<  percstats.confidenceLo() << endl;


}

