#include <iostream>
using namespace std;

int len = 6;
int A[6];

void delete_elem(int pos){
		for(int i = pos; i < len; i++){
				A[i] = A[i+1];
		}
		len--;
}

void check_and_remove_duplicate(int index){
		if(index == len-1){
				return;
		}
		for(int i = 0; i < len; i++){
				if(A[i] == A[index] && i!=index){
						delete_elem(i);
				}
		}
}
void display(){
		for(int i = 0; i < len; i++){
				cout << A[i] << endl;
		}
}
int main(){
		cout << "Enter elements" << endl;
		for(int i = 0; i < len; i++){
				cin >> A[i];
		}
		for(int i = 0; i < len; i++){
				check_and_remove_duplicate(i);
		}
		cout << "Final Array: " << endl;
		display();
}
