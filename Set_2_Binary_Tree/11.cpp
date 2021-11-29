//Jai Shree Ram
//https://www.geeksforgeeks.org/reverse-level-order-traversal/
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
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

vector<int> ans;

void printLevelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
 
    q.push(root);
 
    while (q.empty() == false) {
        Node* node = q.front();
        ans.push_back(node->data);
        q.pop();
 
        if (node->right != NULL)
            q.push(node->right);
 
        if (node->left != NULL)
            q.push(node->left);
    }
}

void solve()
{
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    printLevelOrder(root);
    reverse(ans.begin(), ans.end());
    for(auto& i: ans)
        cout<<i<<" ";
    cout<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     solve();
   
   return 0;
}