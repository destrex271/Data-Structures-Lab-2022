#include <iostream>
using namespace std;


void bubbleSort(int* arr, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j< n; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main(){
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << "Sorted array: " << endl;
	bubbleSort(arr, n);
	for(int i = 0; i < n; i++){
		cout << arr[i];
		if(i == n-1)
			cout << endl;
		else
			cout << ", ";
	}
	delete[] arr;
	return 0;
}
