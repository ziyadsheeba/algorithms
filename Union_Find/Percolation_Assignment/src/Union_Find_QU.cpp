#include "Union_Find_QU.h"

Union_Find_QU::Union_Find_QU(int N){

	id = new int[N];
	for(int i = 0; i < N; i++){
	
		id[i] = i;

	}
}



bool Union_Find_QU::connected_QU(int p, int q){

	return root(p) == root(q);

}

int Union_Find_QU::root(int p){
	
	while(id[p] != p){
	
		p = id[p];

	}
	return p;

}


void Union_Find_QU::union_QU(int p, int q){
	
	int i = root(p);
	int j = root(q);
	id[i] = j;

}


