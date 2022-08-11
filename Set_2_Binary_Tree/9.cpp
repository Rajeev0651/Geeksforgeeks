//Jai Shree Ram
//https://www.geeksforgeeks.org/level-order-traversal-line-line-set-3-using-one-queue/
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--) 

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

vector<int> ans;
void printLevelOrder(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*> Qu;
    Qu.push(root);
    while (!Qu.empty())
    {
        ans.push_back(Qu.front()->data);
        int temp = (Qu.front()->data>=0)?-1:1;
        if(Qu.front()->right)
        {
            Qu.push(Qu.front()->right);
            Qu.front()->right->data = Qu.front()->right->data * temp;
        }
            
        if(Qu.front()->left)
        {
            Qu.push(Qu.front()->left);
            Qu.front()->left->data = Qu.front()->left->data * temp;
        }
        Qu.pop();
    }
}

void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    printLevelOrder(root);
    vector<int> a;
    for(int i=0; i<ans.size(); i++)
    {
        if((ans[i]^ans[i+1])<0)
        {  
            cout<<((ans[i]<0)?ans[i]*-1:ans[i])<<"\n";
        }else   
            cout<<((ans[i]<0)?ans[i]*-1:ans[i])<<" ";
        
    }
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
   
   return 0;
}