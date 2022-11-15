// Symmetrical Triangular
#include <iostream>
using namespace std;

void symm(){
	int r,c;
	cout << "Enter the number of rows and columns" << endl;
	cin >> r >> c;
	int arr[r*(c-1)];
	cout << r*(c-1);
	int counter = 0;
	bool x = true;
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
	cout << "Stored as" << endl;
	for(int i = 0; i < counter; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}