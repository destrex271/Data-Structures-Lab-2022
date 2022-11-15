#include <iostream>
using namespace	std;

int heapSize = 0;
bool found = false;

class BHeap{
	public:
		int val;
		BHeap* left;
		BHeap* right;
		int index;
		friend void minHeapify(BHeap* cur);
		friend BHeap* getParent(BHeap* cur, BHeap* node);

		BHeap(int val, int index){
			this->val = val;
			this->left = NULL;
			this->right = NULL;
			this->index = index;
		}


		void append(BHeap* node){
			BHeap* parent = new BHeap(0, 0);
			parent = getParent(this, node);
			cout << "Parent is " << parent->val << endl;
			found = false;
			cout << "Parent is : " << parent->val << endl;
			cout << "Node is " << node->val << endl;
			if(node->index % 2 == 0){
				cout << "Appending to left" << endl;
				parent->left = node;
			}
			else{
				cout << "Appending to right" << endl;
				parent->right = node;
			}
		}

		void inorder(){
			if(this->left != NULL){
				this->left->inorder();
			}
			cout << this->val << " ";
			if(this->right != NULL){
				this->right->inorder();
			}
		}

		void arrOrder(){
			cout << this->val << " ";
			if(this->left != NULL){
				/* cout << this->left->val << " "; */
				this->left->arrOrder();
			}
			if(this->right != NULL){
				/* cout << this->right->val << " "; */
				this->right->arrOrder();
			}
		}
};

BHeap* getParent(BHeap* heap, BHeap* node){
	if(heap->index == node->index/2){
		found = true;
		cout << "Parent is : " << heap->val << endl;
  	return heap;
	}
	else{
		if(heap->left != NULL && !found){
			cout << "Going left" <<endl;
			return getParent(heap->left, node);
		}
		if(heap->right != NULL && !found){
			cout << "Going right" <<endl;
			return getParent(heap->right, node);
		}
	}
}

void minHeapify(BHeap* cur){
	cout << "HEAPING FOR " << cur->val << endl;
	BHeap* minimum = cur;
	if(cur->left == NULL && cur->right == NULL) return;
	if(cur->left != NULL && cur->left->index <= heapSize && cur->left->val < cur->val){
		minimum = cur->left;
	}else{
		minimum = cur;
	}
	if(cur->right != NULL && cur->right->index <= heapSize && cur->right->val < cur->val){
		minimum =cur->right;
	}else{
		minimum = cur;
	}
	cout << "Minimum is: " << minimum->val << endl;
	if(minimum != cur){
		int temp = cur->val;
		cur->val = minimum->val;
		minimum->val = temp;
		minHeapify(minimum);
	}else{
		if(cur->left != NULL){
			minHeapify(cur->left);
		}
		if(cur->right != NULL){
			minHeapify(cur->right);
		}
	}
}


int main(){
	heapSize = 1;
	cout << "Enter val of:" << endl;
	cout << "1:" << endl;
	int v;
	cin >> v;
	BHeap* root = new BHeap(v, 1);
	BHeap* node;
	for(int i = 2; i < 11; i++){
		cout << i << ": " << endl;
		cin >> v;
		cout << "Adding" << endl;
		node = new BHeap(v, i);
		root->append(node);
		/* minHeapify(root); */
		root->arrOrder();
	}
}
