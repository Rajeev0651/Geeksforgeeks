//Jai Shree Ram
//https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--) 

struct Node
{
    int data;
    int ans;
    Node* left;
    Node* right;

    Node()
    {
        data = 0;
        ans = 0;
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
        cout << node->ans << " ";
        q.pop();
 
        if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
    }
}

Node* compute(Node* node)
{
    if(node==NULL)
        return NULL;
    Node* root = node;
    Node* left = compute(node->left);
    Node* right = compute(node->right);

    if((left==NULL) && (right==NULL))
    {
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    root->ans = (left?left->data+left->ans:0)+(right?right->data+right->ans:0);
    root->left = left;
    root->right = right;
    return root;
}

void solve()
{
    Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    Node* node = compute(root);
    printLevelOrder(node);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}