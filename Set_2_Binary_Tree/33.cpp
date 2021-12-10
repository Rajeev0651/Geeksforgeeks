//Jai Shree Ram
//https://www.geeksforgeeks.org/convert-ternary-expression-binary-tree/
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

Node* tree(string s)
{
    stack<Node*> st;
    Node* node = newNode(s[0]);
    Node* curr = node;
    for(int i=0; i<s.length()-1; i+=2)
    {
        if(s[i+1]=='?')
        {
            curr->left = newNode(s[i+2]);
            st.push(curr);
            curr = node->left;
        }
        else{
            st.top()->right = newNode(s[i+2]);
            st.pop();
        }
    }
    return node;
}

void solve()
{
    string s = "a?b?c:d:e";
    Node* node = tree(s);
    printLevelOrder(node);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}