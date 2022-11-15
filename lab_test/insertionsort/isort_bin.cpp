#include <iostream>
#include <cstring>
using namespace std;

void insertionSort(int* arr, int len){
	int i = 1;
	while(i < len){
		int low = 0;
		int high = i - 1;
		int curInd = i;
		int x = low;
		while(low < high){
			int mid = (low+high)/2;
			if(arr[mid] == arr[curInd]){
				x = 
			}
		}
	}
}

int main(){
	int n;
	cout << "Enter length of array: " << endl;
	cin >> n;
	int arr[n];
	cout << "Enter array" << endl;
	for(int i = 0; i < n; i++){
		cout << "[" << i << "] : "; 
		cin >> arr[i];
	}
	insertionSort(arr, n);
	return 0;
}

