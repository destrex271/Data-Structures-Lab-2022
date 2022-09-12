#include <iostream>
#include <ctime>
using namespace std;

void feedArray(int* arr, int len){
		for(int i = 0; i < len; i++){
				cout << i << ": ";
				cin >> arr[i];
		}
}

void randomData(int* arr, int len){
		srand((unsigned)time(0));
		for(int i = 0; i < len; i++){
				arr[i] = 1+(rand() % 100);
		}
}

void display(int* arr, int len){
		for(int i = 0; i < len-1; i++){
				cout << arr[i] << ", ";
		}
		cout << arr[len-1] << endl;
}

void feed2D(int** arr, int r, int c){
	srand((unsigned)time(0));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
				arr[i][j] = 1+(rand() % 100);
		}
	}
}

void display(int** arr, int r, int c){
	for(int i = 0; i < r; i++){
		cout << "|";
		for(int j = 0; j < c; j++){
			cout << arr[i][j] << " ";
		}
		cout << "|" << endl;
	}
}