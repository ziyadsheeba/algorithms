#include "Union_Find_WQU.h"
#include <iostream>

using namespace std;

int main(){
	
	// number of nodes 
	int N = 10;
	// initializing the Union Find data structure	
	Union_Find_WQU uf(10);
	
	int p;
	int q;

	cout << N << " nodes initialized" << endl;
	cout << "Enter 2 node indices to be connected seperated by a space." << endl;
	cout << "To exit, enter any character." << endl;

	while(cin >> p >> q){
	if(!uf.connected_WQU(p,q)){
	
		uf.union_WQU(p,q);
		cout << "(" << p << ", " << q << ")" << endl;
	}
	else{
	
		cout << "Nodes already connected" << endl;
	}
	
	}

	return 0;

}
