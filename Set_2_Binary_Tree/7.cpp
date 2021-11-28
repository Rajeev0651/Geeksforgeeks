//Jai Shree Ram
//https://www.geeksforgeeks.org/level-order-tree-traversal/
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

void printLevelOrder(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*> Qu;
    Qu.push(root);
    while (!Qu.empty())
    {
        cout<<Qu.front()->data<<" ";
        if(Qu.front()->right)
            Qu.push(Qu.front()->right);
        if(Qu.front()->left)
            Qu.push(Qu.front()->left);
        Qu.pop();
    }
}

void solve()
{
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    printLevelOrder(root);cout<<endl;
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
   
   return 0;
}