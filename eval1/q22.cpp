#include <iostream>
using namespace std;

struct linkedlist{
    int data;
    struct linkedlist *prev;
    struct linkedlist *next;
};
typedef struct linkedlist node;

node *head=NULL, *temp;

void create(int a){
    if(head == NULL){
        head = new node;
        head->data = a;
        head->prev = NULL;
        head->next = head;
        temp = head;
    }
}

void insertEnd(int a){
    if(head!=NULL){
        temp->next = new node;
        temp->next->data = a;
        temp->next->prev = temp;
        temp = temp->next;
        temp->next = NULL;
    }else{
        create(a);
    }
}

void print(){
    node *tp = head;
    // cout << "Printing!" << endl;
    while(tp != NULL){
        cout << tp->data << endl;
        tp = tp->next;
    }
}

void insertBeginning(int a){
    if(head != NULL){
        node *p;
        p = new node;
        p->data = a;
        p->prev = NULL;
        p->next = head;
        head = p;
    }else{
        create(a);
    }
}

node* getValAt(int k){
    node *tp = head;
    int i = 0;
    while(tp != NULL && i < k){
        i++;
        tp = tp->next;
    }
    return tp;
}
void shuffle(int a, int b){
    node* n1 = getValAt(a);
    node* n2 = getValAt(b);
    n1->prev = NULL;
    n2->next = n1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(0);
	int t;
    cin >> t;
    int insert = 0;
    while(t--){
        char s;
        cin >> s;
        if(s == 'I'){
            int a;
            cin >> a;
            if(insert%2 == 0){
                insertBeginning(a);
            }else{
                insertEnd(a);
            }
            insert++;
        }else if(s == 'D'){
            print();
        }
        else if(s=='S'){
            int a,b;
            cin>>a>>b;
            shuffle(a,b);
        }
    }
	return 0;
}