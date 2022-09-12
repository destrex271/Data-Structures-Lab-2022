#include <iostream>
using namespace std;

int A[10];
int len = 10;

int main(){
		for(int i = 0; i < len; i++){
				cin >> A[i];
		}
		for(int i = len-1; i >= 0; i--){
				cout << A[i] << ",";
		}
		cout << endl;
}
