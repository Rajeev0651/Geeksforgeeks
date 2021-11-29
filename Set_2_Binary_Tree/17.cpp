//Jai Shree Ram
//https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
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
};
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

vector<int> leaf;

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    if(node->left==NULL && node->right==NULL)
        leaf.push_back(node->data);
    printInorder(node->left);
    //cout << node->data << " ";
    printInorder(node->right);
}

void solve()
{
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    printInorder(root);
    Node* left = root;
    Node* right = root;
    while (left!=NULL)
    {
        cout<<left->data<<" ";
        left = left->left;
    }
    for(int i=1; i<leaf.size()-1; i++)
        cout<<leaf[i]<<" ";
    stack<int> rt;
     while (right!=NULL)
    {
        rt.push(right->data);
        right = right->right;
    }
    while (!rt.empty())
    {
        cout<<rt.top()<<" ";
        rt.pop();
    }
    
    cout<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();
   
   return 0;
}