//Jai Shree Ram
//https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/
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

    Node()
    {
        data = 0;
        left = NULL;
        right  = NULL;
    }
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

Node* compute(Node* node)
{
    Node* root;
    if(node==NULL)
        return NULL;
    Node* left = compute(node->left);
    Node* right = compute(node->right);

    if((left==NULL) && (right==NULL))
    {
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    root = newNode((left?left->data:0)+(right?right->data:0));
    root->left = left;
    root->right = right;
    return root;
}

void solve()
{
    Node *root = newNode(50);
    root->left = newNode(7);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(1);
    root->right->right = newNode(30);
    Node* node = compute(root);
    printLevelOrder(node);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}