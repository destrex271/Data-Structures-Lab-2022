#include <iostream>
using namespace std;

template <class T>
class Node{
	T data;
	Node* next;
};
template <class T>
class LinkedList{
	private:
		Node<int>* head = NULL, top;

	public:
		LinkedList(T data){
			head->data = data;
			head->next = NULL;
			top = head;
		}
		LinkedList(){
			head->data = 0;
			head->next = NULL;
			top = head;
		}
		void push(T val){
			top = new Node;
			top->data = val;
			top->next = head;
			head = top;
		}
		T pop(){
			if(top == NULL){
				cout << "Stack Underflow!" << endl;
				return -121281;
			}
			T data = top->data;
			head = top->next;
			delete top;
			return data;
		}
		T peek(){
			return top->data;
		}
		void show(){
			Node<T>* y = top;
			while(y != NULL){
				cout << y->data << endl;
				y = y->next;
			}
		}
};

int main(void){
	cout << "Create your own stack!" << endl;
	bool running = false;
	LinkedList ll(10);
	while(running){
		int ch;
		cout << "Enter 1 : Pushing to Stack\nEnter 2 : To pop from stack" << endl;
		switch(ch){
			case 1:
				cout << "Enter the value that you want to push: ";
				int x;
				cin >> x;
				ll.push(x);
				break;
			case 2:
				cout << "Poped: " << ll.pop();
				break;
			default:
				exit(0);
		}
	}
}
