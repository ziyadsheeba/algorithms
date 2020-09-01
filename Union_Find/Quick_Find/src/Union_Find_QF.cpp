#include "Union_Find_QF.h"

Union_Find_QF::Union_Find_QF(int N){

	id = new int[N];
	for(int i = 0; i < N; i++){
	
		id[i] = i;

	}
}

bool Union_Find_QF::connected_QF(int p, int q){

	return id[p] == id[q];

}

void Union_Find_QF::union_QF(int p, int q){

	int pid = id[p];
	int qid = id[q];

	for(int i = 0; i<sizeof(id); i++){
	
		if(id[i] == pid){
		
			id[i] = qid;

		}
	}
}


