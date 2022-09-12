#include <iostream>
using namespace std;

void multiply(int* arr1, int* arr2, int r1, int c1, int r2, int c2){
	int arr[r1][c2];
	for(int i = 0; i < r1; i++){
		for(int j = 0; j < c2; j++){
			arr[i][j] = 0;
		}
	}
	int counter1 = 0, counter2 = 0;
	for(int i = 0; i < r1; i++){
		for(int j = 0; j < r2; j++){
			for(int k = 0; k < c2; k++){
				int elem1 = 0;
				int elem2 = 0;
				int counter1 = 0;
				int counter2 = 0;
				while(true){
					if(arr1[counter1] == i && arr1[counter1+1] == k){
						elem1 = arr1[counter1+2];
						break;
					}
					counter1 += 3;
				}
				while(true){
					if(arr2[counter2] == k && arr2[counter2+1] == j){
						elem2 = arr2[counter2+2];
						break;
					}
					counter2 += 3;
				}
				arr[i][j]+= elem1*elem2;
			}
		}
	}
	cout << "Answer: " << endl;
	for(int i = 0; i < r1; i++){
		cout << "|";
		for(int j = 0; j < c2; j++){
			cout << " " << arr[i][j] << " ";
		}
		cout << "|" << endl;
	}
}