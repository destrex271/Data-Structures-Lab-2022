#include <iostream>
using namespace std;

int main(){
	int m;
	cout << "Enter the dimensions: ";
	cin >> m;
	int arr[2*m];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			int x;
			cout << "[" << i << ":" << j << "] -"; 
			if(i <= j){
				cin >> x;
			}
		}
	}
	return 0;
}
