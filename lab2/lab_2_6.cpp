#include <iostream>
using namespace std;

int main(){
	int r,c;
	cout << "Enter the number of rows and columns: " << endl;
	cin >> r >> c;
	int arr[r][c];
	int m = r, n = c;
	int k = 0, l = 0 , i = 0;
	while(k < r && l < c){
		for(i = l; i < c; i++){
			cin >> arr[k][i];
		}
		k++;
		for(i = k; i < r; i++){
			cin >> arr[i][c - 1];
		}
		c--;
		if(k < r){
			for(i = c - 1; i >= l; i--){
				cin >> arr[r-1][i];
			}
			r--;
		}
		if(l < c){
			for(i = r - 1;i >= k; i--){
				cin >> arr[i][l];
			}
			l++;
		}
	}
	for(int i = 0; i < m; i++){
		cout << "|";
		for(int j = 0; j < n; j++){
			cout << " " << arr[i][j] << " ";
 		}
 		cout << "|" << endl;
	}
}
