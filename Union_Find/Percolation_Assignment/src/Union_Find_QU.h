#ifndef UNION_FIND_QU 
#define UNION_FIND_QU
#include <iostream>

class Union_Find_QU{

	private:
		int *id;

	public:
		Union_Find_QU(int N);
		bool connected_QU(int p, int q);
		void union_QU(int p, int q);
		int root(int p);

};



#endif
