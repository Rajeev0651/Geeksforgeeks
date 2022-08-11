//Jai Shree Ram
//https://www.geeksforgeeks.org/iterative-preorder-traversal/
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--) 

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void printTree(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> node;
    node.push(root);
    while (!node.empty())
    {
        Node* n = node.top();
        node.pop();
        while (n!= NULL)
        {
            if(n->right)
                node.push(n->right);
            cout<<n->data<<" ";
            n = n->left;
        }
    }
    
}

void solve()
{
    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    printTree(root);
    cout<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     solve();
   
   return 0;
}