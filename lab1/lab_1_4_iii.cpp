#include <iostream>
using namespace std;

void display(int** matrix, int rows, int cols){
		for(int i = 0; i < rows; i++){
				cout << "| ";
				for(int j = 0; j < cols; j++){
						cout << matrix[i][j] << " ";
				}
				cout << " |" << endl;
		}
}

void feedMatrix(int** matrix, int rows, int cols){
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < cols; j++){
						cout << "[" << i << "-" << j << "]: ";
						cin >> matrix[i][j];
				}
		}
}

int main(){

		int rows, cols;

		cout << "Enter the number of rows and columns" << endl;
		cin >> rows >> cols;	

		//int matrix[rows][cols];

		int** matrix = new int*[rows];
		for(int i = 0; i < rows; i++){
				matrix[i] = new int[cols];
		}

		//feedMatrix(matrix, rows, cols);
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < cols; j++){
						matrix[i][j] = i;
				}
		}

		cout << "======Original Matrix======" << endl;
		display(matrix, rows, cols);

		for(int i = 0; i < rows; i++){
				for(int j = i; j < cols; j++){
						int temp = matrix[i][j];
						matrix[i][j] = matrix[j][i];
						matrix[j][i] = temp;
				}
		}

		cout << "======Transposed Matrix======" << endl;
		display(matrix, cols, rows);

		return 0;
}
