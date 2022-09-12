#include <iostream>
#include "utils.h"
#include <math.h>
using namespace std;

int main(){
	int r, c;
	cout << "Enter the number of rows and colums: " << endl;
	cin >> r >> c;
	int** arr = new int*[r];
	for(int i = 0; i < r; i++){
		arr[i] = new int[c];
	}

	feed2D(arr, r, c);
	display(arr, r, c);
	cout << "Spiral traversal " << endl;
	int i, k = 0, l = 0;
	while(k < r && l < c){
		for(i = l; i < c; i++){
			cout << arr[k][i] << endl;
		}
		k++;
		for(i = k; i < r; i++){
			cout << arr[i][c - 1] << endl;
		}
		c--;
		if(k < r){
			for(i = c - 1; i >= l; i--){
				cout << arr[r-1][i] << endl;
			}
			r--;
		}
		if(l < c){
			for(i = r - 1;i >= k; i--){
				cout << arr[i][l] << endl;
			}
			l++;
		}
	}
}