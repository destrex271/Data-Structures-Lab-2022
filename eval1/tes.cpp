#include<iostream>
using namespace std;
#define ll long long int

class Node{
public:
    int val;
    Node *next;
    Node *prev;
};


void inser(Node *root,int v){
    if(root->val==-1){
        root->val=v;
        return;
    }
    Node *temp=new Node();
    temp->val=v;
    Node *p;
    p=root;
    p=root->prev;
    p->next=temp;
    root->prev=temp;
    temp->prev=p;
    temp->next=root;
}

void disp(Node* root){
    Node* p;
    p=root;
    Node* q;
    q=p;
    cout<<p->val<<" ";
    do{
        p=p->next;
        if(p!=root&&p->prev!=q){
            q=p;
            cout<<p->val<<" ";
            do{
                p=p->prev;
                cout<<p->val<<" ";
            }while(p!=q&&p!=root);
            q=p->prev;
            p=p->prev;
        }
        else{
            if(p!=root)
            cout<<p->val<<" ";
            q=q->next;
        }
    }while(p&&p!=root);
    cout<<endl;
}

void cut(Node* root,int x,int y){
    int count=1;
    Node* p;
    p=root;
    Node* q;
    Node* r;
    int flag=0;
    q=root->prev;
    do{
        if(count<=y&&count>=x){
            if(p->prev==root->prev)
            flag=1;
        }
        if(count==x-1)
            q=p;
        if(count==y)
            r=p;
        count++;
        p=p->next;
    }while(p&&p!=root);
    p=q->next;
    q->next=r->next;
    if(flag)
    r->next->prev=root->prev;
    else
    r->next->prev=q;
    r->next=p;
    p->prev=r;
    root->prev->next=p;
    root->prev=r;
    q=p;
    p=p->next;
    do{
        p->prev=q;
        p=p->next;
        q=q->next;
    }while(p&&p!=r);
    p->prev=q;
    r->next=root;
}

void solve()
{
    ll n,m,x,y,i,j,k;
    cin>>n;
    int turn=-1;
    Node *root = new Node();
    root->next=root;
    root->prev=root;
    root->val=-1;
    while(n--){
        char func;
        cin>>func;
        if(func=='I'){
            cin>>x;
            inser(root,x);
            if(turn==-1)
                root=root->prev;
            turn*=-1;
        }
        else if(func=='D')
            disp(root);
        else{
            cin>>x>>y;
            cut(root,x,y);
        }
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("error.txt", "w", stderr);
freopen("output.txt", "w", stdout);
#endif

int t=1;
// cout<<t<<endl;
// ${2:is Single Test case?}cin>>t;
// cin>>t;
int n=t;
while(t--)
{
    //cout<<"Case #"<<n-t<<": ";
    solve();
    cout<<"\n";
}

cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
return 0;
}