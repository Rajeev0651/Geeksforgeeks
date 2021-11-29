//Jai Shree Ram
//https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
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
    Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

void printDiagonal(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> st;
    Node* node = root;
    while (node)
    {
        st.push(node);
        node = node->right;

    }
    while(!st.empty())
    {
        int s = st.size();
        for(int i=1; i<=s; i++)
        {
            cout<<st.front()->data<<" ";
            if(st.front()->left!= NULL)
            {
                st.push(st.front()->left);
                if(st.front()->left->right!= NULL)
                {
                    st.push(st.front()->left->right);
                }
            }
            st.pop();
        }
        cout<<"\n";
    }
}

void solve()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->right->left = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(7);
    printDiagonal(root);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
   
   return 0;
}