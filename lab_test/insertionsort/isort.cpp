#include <iostream>
#include <cstring>
using namespace std;

void insertionSort(int* arr, int len){
	int i = 1;
	int totalComp = 0;
	int totalSwaps = 0;
	/* int lowLim = 0; */
	/* int lastSortIndex = 0; */
	cout << "Pass\t" << "Comparisions\t" << "Swaps\t" << "Sorted Array\n";
	while(i < len){
		int curInd = i;
		int comp = 0;
		int swaps = 0;
		cout << i << "\t";
		for(int k = i-1; k >= 0; k--){
			comp++;
			if(arr[curInd] < arr[k]){
				int temp = arr[curInd];
				arr[curInd] = arr[k];
				arr[k] = temp;
				curInd = k;
				swaps++;
			}else{
				break;
			}
		}
		cout << comp << "\t";
		cout << "\t" << swaps << "\t";
		for(int j = 0; j <= i; j++){
			cout << arr[j] << " ";
		}
		cout << endl;
		totalComp += comp;
		totalSwaps += swaps;
		/* lowLim = i; */
		i++;
	}
	cout << "Total Comparisions: " << totalComp << endl;
	cout << "Total Swaps: " << totalSwaps << endl;
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

