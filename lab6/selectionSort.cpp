#include <iostream>
using namespace std;

void selectionSort(int* arr, int len){
	for(int i = 0; i < len - 1; i++){
		int minInd = i;
		for(int j = i+1; j < len; j++){
			if(arr[minInd] > arr[j]){
				minInd = j;
			}
		}
		if(minInd != i){
			int temp = arr[minInd];
			arr[minInd] = arr[i];
			arr[i] = temp;	
		}
	}
}

int main(){
	int n;
	cout << "Enter the number of elements" << endl;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cout << "[" << i << "]: "; 
		cin >> arr[i];
	}
	selectionSort(arr, n);
	cout << "Sorted Array is: " << endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
	return 0;
}



