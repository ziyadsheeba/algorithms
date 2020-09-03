#include "Percolation.h"
#include "Union_Find_QU.h"
#include <iostream>
Percolation::Percolation(int n): uf(n*n + 2), grid_dim(n), open_sites_count(0){
	

	grid.resize(n, std::vector<bool>(n, false));
	for(int i = 0; i<n; i++){
		
		// connect the top virtual node to all grid elements at the top
		uf.union_QU(n*n,i);

		// connect the bottom virtual node to all grid elements at the bottom
		uf.union_QU(n*n+1,n*n-1-i);
	}
}

void Percolation::open(int row, int col){

	if(isOpen(row, col)){return;}
	else{
		open_sites_count += 1;

		// open the node
		grid[row-1][col-1] = true;
		// change from row column format to the vectorized index
		int idx = from2Dto1D(row, col);
	
		// connect node to all open sites in the neighbourhood
		// check if any of the neighbouring nodes are open on the grid
		int shifts[2] = {-1,1};
		for(int i: shifts){; 
		//up, down
		if(!(row+i >grid_dim || row+i <1)){
			if(isOpen(row+i, col)){
				// change from row column format to the vectorized index
				int idx_shift = from2Dto1D(row+i, col);
				// union both nodes 
				uf.union_QU(idx, idx_shift);				
				}
			}
		}
		//left, right
		for(int i: shifts){ 
			if(!(col+i >grid_dim || col+i <1)){
				if(isOpen(row, col+i)){
					// change from row column format to the vectorized index
					int idx_shift = from2Dto1D(row, col+i);
					// union both nodes 
					uf.union_QU(idx, idx_shift);				
				}
			}
		}
	}
}

bool Percolation::isOpen(int row, int column){
	return grid[row-1][column-1];
}

bool Percolation::isFull(int row, int col){
	
	// change from row column format to the vectorized index
	int idx = from2Dto1D(row, col);
	return uf.connected_QU(grid_dim*grid_dim, idx);
} 

int Percolation::numberOfOpenSites(){
	return open_sites_count;
}

bool Percolation::percolates(){return uf.connected_QU(grid_dim*grid_dim, (grid_dim*grid_dim)+1);}

int Percolation::from2Dto1D(int row, int col){
	return (grid_dim*(row-1) + col-1);
}

