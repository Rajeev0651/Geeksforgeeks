//Jai Shree Ram
//https://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
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


void solve()
{
    int in[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    set<int> sets;
    Node* tree = newNode(10);
    stack<Node*> st;
    st.push(tree);
    int f = 1;
    while (!st.empty())
    {
        if(st.top()->flag==0)
        {
            st.top()->left = newNode(in[f]);
            st.top()->flag++;
            if(preLN[f]=='N')
            {
                st.push(st.top()->left);
            }
        }
        else{
            st.top()->right = newNode(in[f]);
            st.pop();
            if(preLN[f]=='N')
                st.push(st.top()->right);
        }
        f++;
    }
    printInorder(tree);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}