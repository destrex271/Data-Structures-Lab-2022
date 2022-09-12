#include <iostream>
#include "utils.h"
using namespace std;


int main(){
		int len;
		cout << "Enter the number of elements" << endl;
		cin >> len;

		int* arr = new int[len];
		feedArray(arr, len);

		int elem;
		cout << "Enter element to search for: ";
		cin >> elem;

		int low = 0;
		int high = len - 1;

		bool flag = true;

		while(low < high){
				int mid = (low+high)/2;
				if(arr[mid] == elem){
						cout << "Foudn at " << mid << endl;
						flag = false;
						break;
				}else if(elem > arr[mid]){
						low = mid+1;
				}else if(elem < arr[mid]){
						high = mid-1;
				}
		}

		if(flag){
				cout << "Element not found" << endl;
		}

}
