//Jai Shree Ram
//https://www.geeksforgeeks.org/find-n-th-node-in-postorder-traversal-of-a-binary-tree/
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

void printPostOrder(Node* node)
{
    if (node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    address.push_back(node);
}


void solve()
{
    struct Node* root = new Node(25);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(18);
    root->left->right = new Node(22);
    root->right->left = new Node(24);
    root->right->right = new Node(32);
    printPostOrder(root);cout<<endl;
    cout<<address[5]->data<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
   
   return 0;
}