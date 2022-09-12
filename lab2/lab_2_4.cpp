#include <iostream>
#include <ctime>
using namespace std;

bool checkLowestInRow(int elem, int r, int c, int** arr){
	for(int i = 0; i < c; i++){
		if(elem > arr[r][i]){
			return true;
		}
	}
	return false;
}

bool checkLowestInCol(int elem, int r, int c, int** arr){
	for(int i = 0; i < r; i++){
		if(elem > arr[i][c]){
			return true;
		}
	}
	return false;
}

void feed2D(int** arr, int r, int c){
	srand((unsigned)time(0));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
				arr[i][j] = 1+(rand() % 100);
		}
	}
}

int main(){
	cout << "Enter the number of rows and cols : ";
	int r,c;
	cin >> r >> c;
	int** arr;
	arr = new int*[r];
	for(int i = 0; i < r; i++){
		arr[i] = new int[c];
	}
	feed2D(arr, r, c);
	cout << "Array is: " << endl;
	for(int i = 0; i < r; i++){
		cout << "|";
		for(int j = 0; j < c; j++){
			cout << " " << arr[i][j] << " ";
		}
		cout << "|" << endl;
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(checkLowestInRow(arr[i][j], i, c, arr) && checkLowestInCol(arr[i][j], i, j, arr)){
				cout << "[" << i << ":" << j << "] :" << arr[i][j] << " is a saddle point!" << endl;
			}
		}
	}
	return 0;
}