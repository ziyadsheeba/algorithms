#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	Stack<string> testStack;

	string input;
	if(testStack.isEmpty()){
		cout << "The stack is empty" << endl;
	}
	cout << "Enter string items to the list: " << endl;
	cout << "To pop an item enter '-' " << endl;
	while(cin >> input){

		if(input == "-"){
			if(!testStack.isEmpty()){
				cout << testStack.pop()  << " popped out of the stack" << endl;
			}
			else{
				testStack.pop();
			}
			
		}
		else if(input == "loop"){
			for(string name: testStack){
				cout << name << endl;
			}
		}
		else{
			cout << "pushed " << input << " to the stack." << endl;
			testStack.push(input);
		}
	}
}
