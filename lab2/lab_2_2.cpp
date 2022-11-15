#include <iostream>
#include "lab_2_2_a.h"
#include "lab_2_2_b.h"
#include "lab_2_2_c.h"
using namespace std;

void getArray(int* arr, int r, int c){
	int counter = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			int x;
			cout << "[" << i << ":" << j << "]" << "->";
			cin >> x;
			if(x!=0){
				arr[counter] = i;
				arr[counter+1] = j;
				arr[counter+2] = x;
				counter += 3;
			}
		}
	}
	// Preview Array
	counter = 0;
	for(int i = 0; i < r; i++){
		cout << "|";
		for(int j = 0; j < c; j++){
			if(arr[counter] == i && arr[counter+1] == j){
				cout << " " << arr[counter+2] << " ";
				counter += 3;
			}else{
				cout << " " << 0 << " ";
			}
		}
		cout << "|" << endl;
	}
}

int main(){
	bool run = true;
	while(run){
		int ch;
		cout << "Enter:\n1. Transpose\n2. Add\n3. Multiply\n Any Key to quit\n";
		cin >> ch;
		int r,c;
		int arr[300];
		int arr2[300];
		switch(ch){
			case 1:
				cout << "Enter the number of rows and columns" << endl;
				cin >> r >> c;
				getArray(arr,r,c);
				transpose(arr, r,c);
				break;
			case 2:
				cout << "Enter the number of rows and columns" << endl;
				cin >> r >> c;
				getArray(arr,r,c);
				getArray(arr2,r,c);
				add(arr,arr2,r,c);
				break;
			case 3:
				int r,c;
				cout << "Enter the number of rows and columns" << endl;
				cin >> r >> c;
				getArray(arr,r,c);
				getArray(arr2,r,c);
				multiply(arr,arr2,r,c,r,c);
				break;
			default:
				cout << "Wrong choice.. Exiting!";
				run = false;
				break;
		}
	}
}