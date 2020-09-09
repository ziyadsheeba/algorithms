#include "Union_Find_WQU.h"

Union_Find_WQU::Union_Find_WQU(int N){

	id   = new int[N];
	size = new int[N];
	for(int i = 0; i < N; i++){
	
		id[i]   = i;
		size[i] = 1;

	}
}



bool Union_Find_WQU::connected_WQU(int p, int q){

	return root(p) == root(q);

}

int Union_Find_WQU::root(int p){
	
	while(id[p] != p){
		
		id[p] = id[id[p]]; //for path compression
		p = id[p];


	}
	return p;

}


void Union_Find_WQU::union_WQU(int p, int q){
	
	int i 	= root(p);
	int j 	= root(q);
	
	if(i == j) return;
	if(size[i]<size[j]) { id[i] = j; size[j] += size[i];} 
	else{id[j] = i; size[i] += size[j];}

}


