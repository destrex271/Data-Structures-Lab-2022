#include <iostream>
using namespace std;

class Node{
		private:
				int val;
				int* next;
		public:
				Node();
				Node(int val, int* next){
						this->val = val;
						this->next = next;
				}
				void setVal(int x){
						this->val = x;
				}
};

class LinkedList{
		Node head;
};
