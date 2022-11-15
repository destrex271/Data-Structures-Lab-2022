#include <iostream>
using namespace std;

void merge(int* arr, int l, int mid, int h){
	int arrLeft[mid-l+1];
	int arrRight[h - mid];
	int len1 = mid-l+1;
	int len2 = h - mid;
	for(int m = 0; m <= mid; m++){
		arrLeft[m] = arr[l+m];
	}
	for(int m = 0; m <= mid; m++){
		arrRight[m] = arr[mid+1+m];
	}
	int arrComb[h-l+1];
	int i = 0, j = 0, k = 0;
	while(i < len1 && j < len2){
		if(arrLeft[i] < arrRight[j]){
			arr[k] = arrLeft[i];
			k++;
			i++;
		}else{
			arr[k] = arrRight[j];
			j++;
			k++;
		}
	}
	while(i < len1){
		arr[k] = arr[i];
		k++;
		i++;
	}
	while(j < len2){
		arr[k] = arr[j];
		k++;
		j++;
	}
}

void mergeSort(int* arr, int l, int h){
	if(l >= h)
		return;
	int mid = (l+h)/2;
	mergeSort(arr, l,mid);
	mergeSort(arr, mid+1, h);
	merge(arr,l,mid,h);
}
int main(){
	int n;
	cout << "Enter the number of elements in the array" << endl;
	cin >> n;
	int arr[n];
	cout << "Copying" << endl;
	for(int i = 0; i < n; i++){
		cout << "[" << i << "]: "; 
		cin >> arr[i];
	}
	cout << "Done" << endl;
	mergeSort(arr,0,n);
	for(int i = 0; i < n; i++){
		cout << arr[i];
		if(i == n-1)
			cout << endl;
		else
			cout << ", ";
	}
}
