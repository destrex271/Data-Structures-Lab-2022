// Upper Triangular
#include <iostream>
using namespace std;

void upperTriangle(){
	int r,c;
	cout << "Enter the number of rows and columns" << endl;
	cin >> r >> c;
	int arr[r+r-1+r-1];
	int counter = 0;
	// Input
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << "[" << i << ":" << j << "] : ";
			if(i <=j ){
				cin >> arr[counter];
				counter++;
			}else{
				int dummy;
				cin >> dummy;
			}
		}
	}
	counter = 0;
	// Preview
	for(int i = 0; i < r; i++){
		cout << "|" << " ";
		for(int j = 0; j < c; j++){
			if(i <= j){
				cout << " " << arr[counter] << " ";
				counter++;
			}else{
				cout << " " << 0 << " ";
			}
		}
		cout << "|" << endl;
	}
}