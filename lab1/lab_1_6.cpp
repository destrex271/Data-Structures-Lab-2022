#include <iostream>
#include "utils.h"
using namespace std;

int main(){
		int len = 10;
		int arr[len];
		randomData(arr, len);

		cout << "======Original Data======" << endl;
		display(arr, len);

		for(int i = 0; i < len - 1; i++){
				for(int j = 0; j < len - i - 1; j++){
						if(arr[j] > arr[j+1]){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
						}
				}
		}

		cout << "======Sorted Data======" <<  endl;
		display(arr, len);

		return 0;
}
