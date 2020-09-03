#include "Percolation.h"
#include "Union_Find_QU.h"
#include <iostream>

using namespace std;
int main(){
	
	// Percolation grid size
	int grid_size = 3;
	bool test1    = true;

	//test1: checking correct initialization of the sites being all blocked
	
	// instintiate a Percolation object
	Percolation perc(grid_size);

	// check if all elements are open or closed
	for (int i = 1; i <= grid_size; i++){
	
		for(int j = 1; j <= grid_size; j++){
		
			if(perc.isOpen(i,j)){
				test1 = false;			
			}
		}
	}
	if(test1){
		cout << "Test 1 passed: all sites are blocked after initialization" << endl;
	}
	else{
		cout << "Test 1 failed: some sites are open after initialization" << endl;
	}

	// test2: checking if opening edge cases works
	bool test2 = true;
	
	for (int i = 1; i<= grid_size; i++){
		perc.open(i,1);
		if(!perc.isOpen(i,1)){test2 = false;}
	}
	
	if(test2){cout << "Test 2 passed. open function works well." << endl;}
	else{cout << "Test 2 failed. open function is faulty." << endl;}

	// test3 check if the grid percolates, it should after opening all the sites on the first column
	bool test3 = true;
	if(!perc.percolates()){test3 = false;}
	if(test3){cout << "Test 3 passed. Percolation functionality works."<< endl;}
	else{cout << "Test 3 failed. Percolation functionality failes." << endl;}

}

