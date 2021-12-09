//Jai Shree Ram
//https://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--) 

struct Node
{
    int data;
    int flag;
    Node* left;
    Node* right;
};
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->flag = 0;
    node->right = node->left = NULL;
    return node;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

pair<int,int> findMax(int in[], int N)
{
    int val = INT_MIN;
    pair<int, int> ans;
    for(int i=0; i<N; i++)
    {
        if(in[i]>val)
        {
            ans.first = in[i];
            val = in[i];
            ans.second = i;
        }
    }
    return ans;
}

Node* compute(int in[], int N)
{
    pair<int, int> ans = findMax(in, N);
    Node* node = newNode(ans.first);
    if(ans.second>0)
        node->left = compute(in, ans.second);
    if(ans.second<N-1)
        node->right = compute(in+ans.second+1, N-ans.second-1);
    return node;
}

void solve()
{
    int in[] = {1, 5, 10, 40, 30, 15, 28, 20};
    Node* tree = compute(in, 8);
    printInorder(tree);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}