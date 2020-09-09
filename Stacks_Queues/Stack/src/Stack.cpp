#include <string>
#include <iostream>

template <class Item>
bool Stack<Item>::isEmpty(){
	return first == NULL;
}

template <class Item>
Stack<Item>::Stack(): first(NULL){};

template <class Item>
void Stack<Item>::push(Item item){
	// storing a pointer to the old top node
	Node<Item> *oldfirst = first;
	// creating a new top node on the memory heap
	first = new Node<Item>();
	// assigning the variables
	first->item = item;
	first->next = oldfirst;
}

template <class Item>
Item Stack<Item>::pop(){
	try{
		if(!this->isEmpty()){
		Node<Item> *newfirst = first->next;
		Item item = first->item;
		// reclaim memory from the heap
		delete first;
		first = NULL;
		// re assign 
		first = newfirst;
		return item;
		}
		else{ throw 1;}
	}
	catch(int e){ 
		std::cout << "Stack is empty. Can't pop elements." << std::endl;
		return "";
	}
}

template<class Item>
Iterator<Item> Stack<Item>::begin(){
	return Iterator<Item>(first);
}

template<class Item>
Iterator<Item> Stack<Item>::end(){
	return Iterator<Item>(NULL);
}

