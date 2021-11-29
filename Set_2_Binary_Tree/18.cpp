//Jai Shree Ram
//https://www.geeksforgeeks.org/density-of-binary-tree-in-one-traversal/
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

int height(Node* node, int &size)
{
    if(node==NULL)
        return 0;
    int leftH = height(node->left, size);
    int rightH = height(node->right, size);
    size++;
    if(leftH>rightH)
        return leftH+1;
    return rightH + 1;
}

void solve()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    int size = 0;
    int H = height(root, size);
    cout<< (float)size/H<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}