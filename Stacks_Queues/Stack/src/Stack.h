/*Stack.h implementation */
#ifndef _STACK_
#define _STACK_
#include <string>


// defining a node item as a struct
template <class Item>
struct Node {
	// object to store (should be a reference)
	Item item;
	// the pointer to the next node in the list
	struct Node *next;
};

// defining the iterator class to loop through the list elements
template<class Item>
class Iterator{
	private:
		Node<Item> *position;
	public:
		// constructor 
		Iterator (Node<Item>* n){
			position = n;
		}
		// overloading the ++ operator
		Iterator& operator++(){
			this->position = position->next;
			return *this;			
		}

		// overloading the == operator
		bool operator==(const Iterator& i){
			return position == i.position;
		}

		bool operator !=(const Iterator& i){
			return position != i.position;
		}

		Item& operator*(){
			return position->item;
		}
};

template <class Item>
class Stack{

	private:
		// first stores a pointer to the first element
		Node<Item> *first;
	public:
		
		Stack();
		// check if the list is empty
		bool isEmpty();
		// adds element to the begining of the list
		void push(Item item);

		// removes the first element of the 
		Item pop();

		// iterator begin 
		Iterator<Item> begin();

		//Iterator end 
		Iterator<Item> end();
	
	};

#include "Stack.cpp"
#endif
