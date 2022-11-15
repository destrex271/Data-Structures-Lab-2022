#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class MaxHeap{
	private:
		int* heap;
		int heapSize = -1;
	public:
		MaxHeap(){
			heap = new int[MAX_SIZE];
		};
		void insert(int x){
			heapSize++;
			heap[heapSize] = x;
			minHeapify(heapSize/2);
		}
		int left(int i){
			return 2*i;
		}
		int right(int i){
			return 2*i + 1;
		}
		void minHeapify(int root){
			cout << "Heapifying " << root << endl;
			int l = left(root);
			int r = right(root);
			int min = root;
			cout << "l: " << heap[l] << " r: " << heap[r] << endl;
			if(l <= heapSize && heap[l] < heap[root]) min = l;
			if(r <= heapSize && heap[r] < heap[root]) min = r;
			cout << "Min is " << heap[min] << endl;
			if(min != root){
				int temp = heap[root];
				heap[root] = heap[min];
				heap[min] = temp;
				minHeapify(min);
			}
		}
		void display(){
			for(int i = 0; i <= heapSize; i++){
				cout << heap[i] << " ";
			}
			cout << endl;
		}
};

int main(){
	MaxHeap h;
	bool running = true;
	while(running){
		cout << "Enter\n\t1. Insert\n\t2. Display\n\tAny to Exit...." << endl;
		int c = 0;
		cin >> c;
		int x = 0;
		switch(c){
			case 1:
				cout << "Enter the number to insert: ";
				x = 0;
				cin >> x;
				h.insert(x);
				break;
			case 2:
				h.display();
				break;
			default:
				running = false;
				break;
		}
	}
}
