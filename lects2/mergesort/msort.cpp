
// This program implements Merge sort on an array of integers
// Author: Akshat Jaimini

#include <iostream>

using namespace std;

void merge(int* arr, int l, int mid, int r){
	int m = mid - l + 1;
	int n = r - mid;
	int i = 0, j = 0, k = 0;
	int c[m+n];
	while(i < m && j < n){
		if(arr[i] < arr[j]){
			c[k] = arr[i];
		}else{
			c[k] = arr[j];
		}
		k++;
	}
	while(i - m > 0){
		c[k] = arr[i];
		i++;
	}
	while(j - n > 0){
		c[k] = arr[j];
		j++;
	}
	k = 0;
	for(int i = l; i <= r; i++,k++){
		arr[i] = c[k];
	}
}

void mergeSort(int* arr, int l, int r){
	if(l < r){
		int mid = (l+r)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}


int main(){
	int arr[10] = {3,7,1,2,5,2,9,10,0};
	mergeSort(arr,0,9);
	return 0;
}
