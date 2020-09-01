#ifndef UNION_FIND_QF 
#define UNION_FIND_QF
#include <iostream>

class Union_Find_QF{

	private:
		int *id;

	public:
		Union_Find_QF(int N);
		bool connected_QF(int p, int q);
		void union_QF(int p, int q);

};



#endif
