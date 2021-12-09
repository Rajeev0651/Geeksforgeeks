//Jai Shree Ram
//https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
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

int search(int in[], int val, int N)
{
    for(int i=0; i<N; i++)
        if(in[i]==val)
            return i;
    return -1;
}

Node* compute(int in[], int post[], int N)
{
    int pos = search(in, post[N-1], N);
    Node* node = newNode(post[N-1]);
    if(pos<0)
        return node;
    if(pos>0)
        node->left = compute(in, post, pos);
    if(pos<N-1)
    {
        node->right = compute(in+pos+1, post+pos, N-pos-1);
    }
    return node;
}

void solve()
{
   int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
   int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
   Node* tree = compute(in, post, 8);
   printLevelOrder(tree);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}