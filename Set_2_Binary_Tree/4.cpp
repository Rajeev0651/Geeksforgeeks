//Jai Shree Ram
//https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/
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
    Node* next;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

vector<Node*> address;

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    address.push_back(node);
    //cout << node->data << " ";
    printInorder(node->right);
}

void Inorder(Node* node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    node->next = address.back();
    if(node->next)
        cout << node->next->data << " ";
    else   
        cout<<-1;
    address.pop_back();
    Inorder(node->right);
}

void solve()
{
    struct Node *root = new Node(10);
    root->left        = new Node(8);
    root->right       = new Node(12);
    root->left->left  = new Node(3);
    printInorder(root);cout<<endl;
    address.push_back(nullptr);
    reverse(address.begin(), address.end());
    address.pop_back();
    Inorder(root);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
   
   return 0;
}