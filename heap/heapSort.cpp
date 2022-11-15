#include <iostream>
using namespace std;

class BST{
	private:
		int val;
		BST* left;
		BST* right;
	public:
		BST(int val = 0, BST* left=NULL, BST* right=NULL){
			this->left = left;
			this->right = right;
			this->val = val;
		}
		int getVal(){return val;}
		void append(BST* a){
			if(a->getVal() < this->val){
				if(this->left == NULL){
					this->left = a;
				}else{
					this->left->append(a);
				}
			}else if(a->getVal() > this->val){
				if(this->right == NULL){
					this->right = a;
				}else{
					this->right->append(a);
				}
			}else{
				cout << "Already exists" << endl;
			}
		}
		void inorder(int* size){
			if(this->left != NULL){
				*size++;
				this->left->inorder(size);
			}
			cout << this->val << endl;
			if(this->right != NULL){
				*size++;
				this->right->inorder(size);
			}
		}
		void preorder(){
			cout << this->val << endl;
			if(this->left != NULL){
				this->left->preorder();
			}
			if(this->right != NULL){
				this->right->preorder();
			}
		}
		void postorder(){
			if(this->left != NULL){
				this->left->postorder();
			}
			if(this->right != NULL){
				this->right->postorder();
			}
			cout << this->val << endl;
		}
		bool search(int val){
			if(this->val == val){
				return true;
			}else if(this->left != NULL && this->val > val){
				return this->left->search(val);
			}else if(this->right != NULL && this->val < val){
				return this->right->search(val);
			}else{
				return false;
			}
		}
		void deleteNodeC(int req, int side){
			if(req == 1){
				(side == -1) ? delete this->left : delete this->right;
			}else{
				if(side == -1){
					this->left->deleteNodeC(req--,side);
				}else{
					this->right->deleteNodeC(req--,side);
				}
			}
		}
		void deleteNode(int v){
			if(this->left != NULL && v<this->val){
				if(this->left->val == v){
					BST* a = this->left;
					this->left = this->left->left;
					this->right = this->left->right;
					delete a;
				}else{
					this->left->deleteNode(v);
				}
			}else if(this->right != NULL && this->val < v){
				if(this->right->val == v){
					BST* a = this->right;
					this->left = this->right->left;
					this->right = this->right->right;
					delete a;
				}
			}
		}
		int parent(int v){
			if(v < this->val && this->left != NULL){
				if(this->left->val == v){
					return this->val;
				}else{
					this->left->parent(v);
				}
			}else if(v > this->val && this->right != NULL){
				if(this->right->val == v){
					return this->val;
				}else{
					this->right->parent(v);
				}
			}else{
				return -999999;
			}
		}
		int minimumNode(){
			if(this->left == NULL){
				return this->val;
			}
			return this->left->minimumNode();
		}
		int maximumNode(){
			if(this->right == NULL){
				return this->val;
			}
			return this->right->maximumNode();
		}
};

int main(){
	bool running = true;
	int choice;
	BST* root = NULL;
	BST* tree;
	while(running){
		cout << "Enter choice,\n\t1. Create\n\t2. Append\n\t3. Inorder\n\t4. Preorder\n\t5. Postorder\n\t6. Delete from Left\n\t7. Delete from right\n\t8. Searchn\n\t9. Find Minimum\n\t10. Find Maximum\n\t11. Find Parent of\n\t12. Delete Node\n\tAny. Exit" << endl;
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Enter val: ";
				int x;
				cin >> x;
				root = new BST(x);
				break;
			case 2:
				cout << "Enter val: ";
				int a;
				cin >> a;
				tree = new BST(a);
				root->append(tree);
				break;
			case 3:
				root->inorder();
				break;
			case 4:
				root->preorder();
				break;
			case 5:
				root->postorder();
				break;
			case 6:
				int y;
				cout << "Enter index to delete from left: ";
				cin >> y;
				root->deleteNodeC(y,-1);
				break;
			case 7:
				int z;
				cout << "Enter index to delete from right: ";
				cin >> z;
				root->deleteNodeC(z,1);
				break;
			case 8:
				int v;
				cout << "Enter val to search: ";
				cin >> v;
				if(root->search(v))
					cout << "Found" << endl;
			case 9:
				int e;
				cout << "Enter the val to delete: ";
				cin >> e;
				root->deleteNode(e);
			case 11:
				int vx;
				cout << "Enter value whose parent you want to find: ";
				cin >> vx;
				cout << "Parent is: " << root->parent(vx) << endl;
				break;
			case 12:
				int vy;
				cout << "Enter value to delete: ";
				cin >> vy;
				cout << "Deleting..." << endl;
				root->deleteNode(vy);
				break;
			default:
				running = false;
				break;
		}
	}
	return 0;
}
