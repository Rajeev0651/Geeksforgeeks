//Jai Shree Ram
//
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


void solve()
{
    int in[] = {10, 12, 15, 25, 30, 36};
    Node* tree = newNode(10);
    queue<Node*> qu;
    qu.push(tree);
    qu.push(tree);
    int N = 1;
    while(N<=5)
    {
        qu.front()->left = newNode(in[N]);
        qu.pop();
        if(N+1<=5)
            qu.front()->right = newNode(in[N+1]);
        qu.push(qu.front()->left);
        qu.push(qu.front()->left);
        if(N+1<=5)
        {
            qu.push(qu.front()->right);
            qu.push(qu.front()->right);
        }
        
        qu.pop();
        N+=2;
    }
    printLevelOrder(tree);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}