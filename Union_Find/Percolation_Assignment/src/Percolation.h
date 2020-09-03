#ifndef _PERCOLATION_
#define _PERCOLATION_
#include "Union_Find_QU.h"
#include <vector>
using namespace std;
class Percolation{
	private:
		std::vector<std::vector<bool>> grid;
		Union_Find_QU uf;
		int open_sites_count;
		int grid_dim;
	public:
		//create an n-by-n grid, all sites initially blocked
		Percolation(int n);
		
		//opens the site (row, col) if it is not open already
		void open(int row, int col);

		//is the site (row, col) open?
		bool isOpen(int row, int col);

		//is the site (row, col) full?
		bool isFull(int row, int col);

		//returns the number of open sites
		int numberOfOpenSites();

		//does the system percolate?
		bool percolates();

		//transforms 2d indices into 1d indices
		int from2Dto1D(int row, int col);

};

#endif
