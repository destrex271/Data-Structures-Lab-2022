#include <iostream>
using namespace std;

void insertionSort(int* arr, int n){
	for(int i = 1; i < n; i++){
		int curInd = i;
		for(int j = i; j >= 0; j--){
			if(arr[curInd] < arr[j]){
				int temp = arr[curInd];
				arr[curInd] = arr[j];
				arr[j] = temp;
				curInd = j;
			}
		}
	}
}

int main(){
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	int* arr = new int[n];
	cout << "Enter the values in the array" << endl;
	for(int i = 0; i < n; i++){
		cout << "[" << i << "]: ";
		cin >> arr[i];
	}
	insertionSort(arr,n);
	cout << "Sorted Array is: " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i];
		if(i == n-1){
			cout << endl;
		}else{
			cout << ", ";
		}
	}
	delete[] arr;
}
