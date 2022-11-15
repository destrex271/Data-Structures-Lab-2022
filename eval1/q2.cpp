#include <iostream>
using namespace std;

struct linkedlist{
    int data;
    struct linkedlist *prev;
    struct linkedlist *next;
};
typedef struct linkedlist node;

node *head=NULL, *temp;

bool shuffled = false;

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
    bool circDetected = false;
    while(tp != NULL){
        if(tp->prev == NULL && tp != head){
            circDetected = true;
            break;
        }
        cout << tp->data << " ";
        tp = tp->next;
    }
    if(circDetected){
        node* tp1 = tp;
        do{
            cout << tp->data << " ";
            tp = tp->next;
        }while(tp != tp1);
        cout << tp->data;
    }
    cout << endl;
}

void insertBeginning(int a){
    if(head != NULL){
        node *p;
        p = new node;
        p->data = a;
        p->prev = NULL;
        head->prev = p;
        p->next = head;
        head = p;
    }else{
        create(a);
    }
}

node* getNodeAt(int k){
    node* t=  head;
	for(int i=1;i<k;i++){
		t = t->next;
	}
	return t;
}

void shuffle(int a, int b){
    if(!shuffled){
        node* n1 = getNodeAt(a);
        node* n2 = getNodeAt(b);
        n2->next->prev = n1->prev;
        n2->next->next = n1;
        n1->prev->next = n2->next;
        n1->prev = NULL;
        n2->next = n1;
        shuffled = true;
    }else{
        node* n1 = getNodeAt(a);
        // cout << n1->data << endl;
        node* n2 = getNodeAt(b);
        // cout << n2->data << endl;
        node* p = n2->next;
        // cout << p->data << endl;
        node* x = n2->next;
        x = x->next;
        // cout << x->data;
        while(x->next != n1 && x->next != n2 && x->next != p){
            x = x->next;
            // cout << x->data << endl;
        }
        p->prev = x;
        n1->prev->next = p;
        x->next = n1;
        // cout << p->next->data << endl;
        n2->next = n1;
    }
}

int main(){
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
        }else if(s == 'S'){
            int a, b;
            cin >> a >> b;
            shuffle(a,b);
        }
    }
}