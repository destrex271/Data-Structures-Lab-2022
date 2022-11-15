#include <iostream>

using namespace std;

int A[100];

void create(int len){
		cout << "Enter elemet at: " << endl;
		for(int i = 0; i  < len; i++){
				cout << i << ": ";
				cin >> A[i];
		}
}

void display(int len){
		for(int i = 0; i < len; i++){
				cout << A[i] << ", ";
		}
		//cout << endl;
}

int insert(int elem, int pos, int len){
		for(int i = len-1; i >= pos; i--){
				A[i+1] = A[i];
		}
		A[pos] = elem;
		return len+1;
}

int delete_elem(int pos, int len){
		for(int i = pos; i < len; i++){
				A[i] = A[i+1];
		}
		return len-1;
}

int linear_search(int len, int elem){
		for(int i = 0; i < len; i++){
				if(A[i] == elem){
						return i;
				} 
		}
		return -1;
}

int binary_search(int len, int elem){
		int low = 0;
		int high = len-1;
		while(low <= high){
				int mid = (low+high)/2;
				if(A[mid] == elem){
						return mid;
				}else if(elem > A[mid]){
						low = mid + 1;
				}else if(elem < A[mid]){
						high = mid-1;
				}
		}
		return -1;
}

int main(){
		int len = 10;
		bool terminate = false;
		
		while(!terminate){
		     cout << "Enter\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n6. Exit\n";
		     int ch;
		     cin >> ch;
		     int pos, elem;
		     switch(ch){
				   case 1:
						create(len);
						break;
				   case 2:
						display(len);
						cout << endl;
						break;
				   case 3:
						cout << "Enter element to insert and position to insert in" << endl;
						cin >> elem >> pos;
						len = insert(elem, pos, len);
						cout << "The new array is : " << endl;
						display(len);
						cout << endl;
						break;
				   case 4:
						cout << "Enter the element pos to delete: ";
						cin >> pos;
						if(pos >= len || pos < 0){
								cout << "Operation Not allowed!" << endl;
								break;
						}
						len = delete_elem(pos, len);
						cout << "New array is : ";
						display(len);
						cout << endl;
						break;
				   case 5:
				      {
						cout << "Enter element to search" << endl;
						cin >> elem;
						int index = linear_search(len, elem);
						if(index < 0){
								break;
						}
						cout << "Element found at " << index << endl;
						display(index);
						cout << "[" << A[index] << "]" <<  endl;
						break;
				      }
				   case 6:
						cout << "Thanks for using" << endl;
						return 0;
				}
		}

		return 0;
}
