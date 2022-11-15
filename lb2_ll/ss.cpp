#include <iostream>
using namespace std;

struct linkedlist{
		int data;
		struct linkedlist *next;
};
typedef struct linkedlist node;

node *head=NULL, *temp;
// NULL pointer: does not point to any memeory location; takes 0 as default val (memoory address)
// Uninitialized pointer does point to a memory location; takes garbage value as default val until assigned;

void create(){
		cout << "Enter value" <<  endl;
		if(head == NULL){
				head = new node; // Allocate the memory
				cin >> head->data;
				head->next = NULL;
				temp = head;
		}
}

void insertEnd(){
		if(head!=NULL){
				temp->next = new node;
				cin >> temp->next->data;
				temp = temp->next;
		}else{
				cout << "LinkedList does not exist now" << endl;		
		}
}

void print(){
		node *tp = head;
		cout << "Printing!" << endl;
		while(tp!= NULL){
				cout << tp->data << endl;
				tp = tp->next;
		}
}

void insertBeginning(){
		node *p;
		p = new node;
		cout << "Enter data for new node" << endl;
		cin >> p->data;
		p->next = head;
		head = p;
}


void insertAny(){
		cout << "Enter the number where you want to insert this item" << endl;
		int num;
		cin >> num;
		node *tp = head;
		int i = 0;
		while(tp->data != num){
				tp = tp->next;
		}
		cout << "Enter val to insert" << endl;
		cin >> num;
		node* p = new node;
		p->data = num;
		p->next = tp->next;
		tp->next = p;
}

node* delete_end(){
		if(head->next == NULL){
				delete head;
				node *p = NULL;
				return p;
		}
		node *tp = new node;
		tp = head;
		while(tp->next->next != NULL){
				tp = tp->next;
		}
		node* retVal = tp;
		delete tp->next;
		tp->next = NULL;
		temp = tp;
		return tp;
}

node* delete_beg(){
		node* p = head;
		int data = head->data;
		head = head->next;
		delete p;
		p = new node;
		p->data = data;
		return p;
}

void delete_mid(){
		node* tp = head;
		int num;
		cout << "Enter the val you want to delete" << endl;
		cin >> num;
		// cout << "Looping" << endl;
		while(tp->next->data != num){
				// cout << tp->next->data;
				tp = tp->next;
		}
		node* a = tp->next;
		tp->next = a->next;
		delete a;
}

void insertBef(){
		node* tp;
		tp = head;
		cout << "Enter val to insert before" << endl;
		int num;
		cin >> num;
		while(tp->next->data != num){
				tp = tp->next;
		}
		node* p = new node;
		cin >> p->data;
		p->next = tp->next;
		tp->next = p;
}

int search(){
		int elem;
		cout << "Enter element to search " << endl;
		cin >> elem;
		node* tp = head;
		int i = 0;
		while(tp != NULL){
				if(tp->data == elem){
						cout << "Element found at " << i << endl;
						break;
				}
				i++;
				tp = tp->next;
		}
}

int main(){

		bool running = true;
		while(running){
				int ch;
				cout << "Enter choice : " <<  endl;
				cin >> ch;
				switch(ch){
						case 1:
								create();
								break;
						case 2:
								print();
								break;
						case 3:
								insertEnd();
								break;
						case 4:
								insertBeginning();
								break;
						case 5:
								insertAny();
								break;
						case 6:
								insertBef();
								break;
						case 7:
								delete_end();
								break;
						case 8:
								delete_beg();
								break;
						case 9:
								delete_mid();
								break;
						default:
								running = false;
								break;
				}
		}

		return 0;
}
