#include <iostream>
using namespace std;


int** createMatrix(int rows, int cols){
		int** matrix = new int*[rows];
		for(int i = 0; i < rows; i++){
				matrix[i] = new int[cols];
		}
		return matrix;
}

void feedMatrix(int** matrix, int rows, int cols){
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < cols; j++){
						cout << "[" << i << "-" << j << "] : ";
						cin >> matrix[i][j];
				}
		}
}

void displayMatrix(int** matrix, int rows, int cols){
		for(int i = 0; i < rows; i++){
				cout << "| ";
				for(int j = 0; j < cols; j++){
						cout << matrix[i][j] << " ";
				}
				cout << "|" << endl;
		}
		cout << endl;
}

int main(){
		int rows1, cols1, rows2, cols2;
		
		cout << "Enter rows and cols for first matrix" << endl;
		cin >> rows1 >> cols1;	

		cout << "Enter rows and cols for second matrix" << endl;
		cin >> rows2 >> cols2;

		if(!rows2 == cols1){
				cout << "Operation not permitted!" << endl;
				return -1;
		}
		
		int** matrix1 = createMatrix(rows1, cols1);
		int** matrix2 = createMatrix(rows2, cols2);

		cout << "Enter elements for Matrix 1" << endl;
		feedMatrix(matrix1, rows1, cols1);

		cout << "Enter elements for Matrix 2" << endl;
		feedMatrix(matrix2, rows2, cols2);

		int** matrix3 = createMatrix(rows1, cols2);

		for(int i = 0; i < rows1; i++){
				for(int j = 0; j < cols2; j++){
						for(int k = 0; k < cols1; k++){
								matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
								// cout << matrix1[i][k] << " " << matrix2[k][j] << " " << matrix3[i][j] << endl;
							}
				}
		}

		displayMatrix(matrix3, rows1, cols2);

		delete[] matrix3;
		delete[] matrix2;
		delete[] matrix1;

		return 0;
}
