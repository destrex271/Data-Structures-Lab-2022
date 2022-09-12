#include <iostream>
#include "lab_2_1_a.h"
#include "lab_2_1_b.h"
#include "lab_2_1_c.h"
#include "lab_2_1_d.h"
#include "lab_2_1_e.h"
using namespace std;

int main(){
	bool exec = false;
	while(!exec){
		cout << "Enter\n1: Diagonal Matrix\n2: Tridiagonal Matrix\n3: Lower Triangular Matrix\n4: Upper Triangular\n5: Symmetrical\n";
		int ch = 0;
		cin >> ch;
		switch(ch){
			case 1:
				diagonal();
				break;
			case 2:
				tridiagonal();
				break;
			case 3:
				lowerTriangle();
				break;
			case 4:
				upperTriangle();
				break;
			case 5:
				symm();
				break;
			default:
				cout << "Wrong choice..Quiting!";
				exec = !exec;
				break;
		}
	}
	return 0;
}