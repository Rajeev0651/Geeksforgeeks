//Jai Shree Ram
//https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--) 

struct Node
{
    char data;
    Node* left;
    Node* right;
};
Node *newNode(char data)
{
    Node *node = new Node();
    node->data = data;
    node->right = node->left = NULL;
    return node;
}
int search(int in[], int N, char value)
{
    for(int i=0; i<N; i++)
        if(in[i]==value)
            return i;
    return -1;
}

Node* compute(int in[], int pre[], int N)
{
    Node* root = newNode(pre[0]);
    int index = search(in, N, pre[0]);
    if(index==-1)
        return NULL;
    if(index>0)
        root->left = compute(in, pre+1, index);
    if(index<N-1)
        root->right = compute(in+index+1, pre+index+1, N-index-1);
    return root;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void solve()
{
    int in[] = {'D','B','E','A','F','C'};
    int pre[] = {'A','B','D','E','C','F'};
    Node* tree = compute(in, pre, 6);
    printInorder(tree);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}