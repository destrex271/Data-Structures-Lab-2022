#include <iostream>
using namespace std;

void diagonal(){
	cout << "Enter the number of rows and columns: " <<  endl;
	int r = 0,c = 0;
	cin >> r >> c;
	int arr[r];
	// Taking Input
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << "[" << i << ":" << j << "]";
			if(i == j){
				cin >> arr[i];
			}else{
				int dummy;
				cin >> dummy;
			}
		}
	}
	// Printing
	for(int i = 0; i < r; i++){
		cout << "|" ;
		for(int j = 0; j < c; j++){
			if(i == j){
				cout << arr[i] << " ";
			}else{
				cout << 0 << " ";
			}
		}
		cout << "|" << endl;
	}
}