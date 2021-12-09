//Jai Shree Ram
//https://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/
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

pair<int, int> search(int in[], int N, int val)
{
    pair<int, int> ans(-1, -1);
    for(int i=0; i<N; i++)
    {
        if(in[i]==val && ans.first==-1)
        {
            ans.first = i;
        }
        else if(in[i]==val)  
            ans.second = i;
    }
    return ans;
}

void solve()
{
    int parent[] = {1, 5, 5, 2, 2, -1, 3};
    int index = -1;
    queue<Node*> qu;
    for(int i=0; i<7; i++)
        if(parent[i]==-1)
        {
            qu.push(newNode(i));
            break;
        }
    Node* tree = qu.front();
    while (!qu.empty())
    {
        pair<int, int> ans = search(parent, 7, qu.front()->data);
        if(ans.first!=-1)
        {
            qu.front()->left = newNode(ans.first);
            qu.push(qu.front()->left);
            //cout<<qu.front()->data<<" ";
        }
            
        if(ans.second!=-1)
        {
            qu.front()->right = newNode(ans.second);
            qu.push(qu.front()->right);
        }    
        qu.pop();
    }
    //cout<<tree->left->data<<" ";
    printLevelOrder(tree);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}