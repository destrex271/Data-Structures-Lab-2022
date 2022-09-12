#include <iostream>
using namespace std;

void add(int* arr1, int* arr2, int r, int c){
	int counter1 = 0;
	int counter2 = 0;
	int arr[3*r*c];
	int counter3 = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			int elem1 = 0;
			int elem2 = 0;
			if(arr1[counter1] == i && arr1[counter1+1] == j){
				elem1 = arr1[counter1+2];
				counter1 += 3;
			}
			if(arr2[counter2] == i && arr2[counter2+1] == j){
				elem2 = arr2[counter2+2];
				counter2 += 3;
			}
			if(elem1+elem2 != 0){
				arr[counter3] = i;
				arr[counter3+1] = j;
				arr[counter3+2] = elem1+elem2;
				counter3 +=3;
			}
		}
	}

	counter3 = 0;
	cout << "Answer: " << endl;
	for(int i = 0; i < r; i++){
		cout << "|";
		for(int j = 0; j < c; j ++){
			if(arr[counter3] == i && arr[counter3+1] == j){
				cout << " " << arr[counter3+2] << " ";
				counter3 += 3;
			}else{
				cout << " " << 0 << " ";
			}
		}
		cout << "|" << endl;
	}
}