//Jai Shree Ram
//https://www.geeksforgeeks.org/replace-node-binary-tree-sum-inorder-predecessor-successor/
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--) 

vector<int> v,ans;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    v.push_back(node->data);
    //cout << node->data << " ";
    printInorder(node->right);
}
void Inorder(Node* node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    node->data = ans.back();
    ans.pop_back();
    Inorder(node->right);
}

void printPreorder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
void solve()
{
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);
    printPreorder(root);cout<<endl;
    v.push_back(0);
    printInorder(root);
    v.push_back(0);
    for(int i=1; i<v.size()-1; i++)
    {
        ans.push_back(v[i-1]+v[i+1]);
    }
    reverse(ans.begin(), ans.end());    
    for(auto &i : ans)
        cout<<i<<" ";
    cout<<"\n";
    Inorder(root);
    printPreorder(root);cout<<endl;
    
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     solve();
   
   return 0;
}