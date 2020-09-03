#include "Percolation.h"
#include "Union_Find_WQU.h"
#include "PercolationStats.h"
#include <random>
#include <math.h>
#include <iostream>

PercolationStats::PercolationStats(int n, int trials){
	
	// declare the thresholds array
	thresholds 	   = new double[trials];
	num_experiments    = trials;  	

	// instantiate a random integer engine and a distribution
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,n);
	for(int i= 0; i<trials; i++){

		//instantiate an instance of the percolation class 
		Percolation perc(n);			
		while(!perc.percolates()){
					
			//draw random row and column indices
			int row = distribution(generator);
		        int col = distribution(generator);			
			//open the drawn site
			perc.open(row, col);
		}
		thresholds[i] = double(perc.numberOfOpenSites());
		thresholds[i] = thresholds[i]/(n*n);
	}
}

double PercolationStats::mean(){

	double mean_val = 0;
	for(int i = 0; i<num_experiments; i++){
		mean_val += thresholds[i];	
	}	
	return (mean_val/num_experiments);
}
double PercolationStats::stddev(){
	double std = 0;
	double mean_val = mean();
	for(int i = 0; i<num_experiments; i++){
		std += pow(thresholds[i] - mean_val, 2);	
	}
	return sqrt(std/(num_experiments -1));
}

double PercolationStats::confidenceLo(){
	return mean()-1.96*(stddev()/sqrt(num_experiments));
}
double PercolationStats::confidenceHi(){
	return mean()+1.96*(stddev()/sqrt(num_experiments));
}
