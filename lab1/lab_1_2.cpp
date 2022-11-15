#include <iostream>

using namespace std;

int main(){
		int* A = new int[10];
		cout << "Enter elments" << endl;
		for(int i = 0; i < 10; i++){
				cin >> A[i];
		}
		int min = A[0];
		int max = A[0];
		for(int i = 1; i < 10; i++){
				if(A[i] < min){
						min = A[i];
				}
				if(A[i] > max){
						max = A[i];
				}
		}
		cout << "Max: " << max << "\nMin: " << min << endl; 
}
