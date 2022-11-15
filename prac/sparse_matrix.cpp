#include <iostream>
using namespace std;

int main(){
	int m;
	cout << "Enter the dimensions of the mXm matrix" << endl;
	cin >> m;
	int arr[3*m];
	int k = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			cout << "[" << i << ":" << j << "] - ";
			int x;
			cin >> x;
			if(x != 0){
				arr[k] = i;
				arr[k+1] = j;
				arr[k+2] = x;
				cout << "saving" << endl;
				k += 3;
			}
		}
	}
	k = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			if(arr[k] == i && arr[k+1] == j){
				cout << arr[k+2] << endl;
				k += 3;
			}else{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}

