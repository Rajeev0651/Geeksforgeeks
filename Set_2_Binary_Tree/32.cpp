//Jai Shree Ram
//https://www.geeksforgeeks.org/convert-given-binary-tree-tree-holds-logical-property/
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

void printLevelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
 
    q.push(root);
 
    while (q.empty() == false) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
    }
}

Node* tree(Node* node)
{
    if(node==NULL)
        return node;
    Node* left = tree(node->left);
    Node* right = tree(node->right);

    if(left)
    {
        Node* root = newNode((left->data) & (right->data));
        root->left = left;
        root->right = right;
        return root;
    } 
    else
        return node;
}

void solve()
{
    Node *root=newNode(0);
    root->left=newNode(1);
    root->right=newNode(0);
    root->left->left=newNode(0);
    root->left->right=newNode(1);
    root->right->left=newNode(1);
    root->right->right=newNode(1);
    Node* node = tree(root);
    printLevelOrder(node);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}