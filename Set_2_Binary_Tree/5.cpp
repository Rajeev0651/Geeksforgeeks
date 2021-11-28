//Jai Shree Ram
//https://www.geeksforgeeks.org/find-n-th-node-inorder-traversal/
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
    Node* next;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

vector<Node*> address;

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    address.push_back(node);
    //cout << node->data << " ";
    printInorder(node->right);
}


void solve()
{
    struct Node *root = new Node(10);
    root->left        = new Node(20);
    root->right       = new Node(30);
    root->left->left  = new Node(40);
    root->left->right  = new Node(50);
    printInorder(root);cout<<endl;
    cout<<address[3]->data<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
   
   return 0;
}