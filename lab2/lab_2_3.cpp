#include <iostream>
using namespace std;

int rowsum(int i, int c, int** arr){
	int sum = 0;
	for(int j = 0; j < c; j++){
		sum += arr[i][j];
	}
	return sum;
}

int colsum(int j, int r, int** arr){
	int sum = 0;
	for(int i = 0; i < r; i++){
		sum += arr[i][j];
	}
	return sum;
}

void get(int** arr, int r, int c){
	for(int i = 0; i < r; i++){
		cout << "Row " << i << ": " << rowsum(i,r,arr) << endl;
	}
	for(int i = 0; i < c; i++){
		cout << "Col " << i << ": " << colsum(i,r,arr) << endl;
	}
}

int main(){
	int** arr = new int*[4];
	for(int i = 0; i < 4; i++){
		arr[i] = new int[4];
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			arr[i][j] = j+i;
		}
	}
	for(int i = 0; i < 4; i++){
		cout << "|";
		for(int j = 0; j < 4; j++){
			cout << " " << arr[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "OK" << endl;
	get(arr, 4, 4);
	return 0;
}