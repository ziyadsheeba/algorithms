#include "Union_Find_QU.h"
#include <iostream>

using namespace std;

int main(){
	
	// number of nodes 
	int N = 10;
	// initializing the Union Find data structure	
	Union_Find_QU uf(10);
	
	int p;
	int q;

	cout << N << " nodes initialized" << endl;
	cout << "Enter 2 node indices to be connected seperated by a space." << endl;
	cout << "To exit, enter any character." << endl;

	while(cin >> p >> q){
	if(!uf.connected_QU(p,q)){
	
		uf.union_QU(p,q);
		cout << "(" << p << ", " << q << ")" << endl;
	}
	else{
	
		cout << "Nodes already connected" << endl;
	}
	
	}

	return 0;

}
