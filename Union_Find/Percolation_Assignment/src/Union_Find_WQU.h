#ifndef UNION_FIND_WQU 
#define UNION_FIND_WQU
#include <iostream>

class Union_Find_WQU{

	private:
		int *id;
		int *size;

	public:
		Union_Find_WQU(int N);
		bool connected_WQU(int p, int q);
		void union_WQU(int p, int q);
		int root(int p);
};

#endif
