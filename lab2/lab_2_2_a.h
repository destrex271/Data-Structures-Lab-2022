#include <iostream>
using namespace std;

void transpose(int* arr, int r, int c){
	cout << "Transpose" << endl;
	for(int i = 0; i < c; i++){
		cout << "|";
		for(int j = 0; j < r; j++){
			int counter = 0;
			while(true){
				if(arr[counter] == j && arr[counter+1] == i){
					cout << arr[counter+2] << " ";
					break;
				}
				counter += 3;
			}
		}
		cout << "|" << endl;
	}
}