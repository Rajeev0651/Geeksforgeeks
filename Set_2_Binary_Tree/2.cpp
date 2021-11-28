//Jai Shree Ram
//https://www.geeksforgeeks.org/find-all-possible-trees-with-given-inorder-traversal/
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--) 

struct Node
{
    int data;
    Node* left, *right;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void printPreorder(Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

vector<Node*> generateTree(int in[], int left, int right)
{
    vector<Node*> trees;

    if(left>right)
    {
        trees.push_back(nullptr);
        return trees;
    }

    for(int i=left; i<=right; i++)
    {
        vector<Node*> leftTree = generateTree(in, left, i-1);
        vector<Node*> rightTree = generateTree(in, i+1, right);

        for(Node* left: leftTree)
        {
            for(Node* right: rightTree)
            {
                Node* tree = new Node(in[i], left, right);
                trees.push_back(tree);
            }
        }
    }
    return trees;
}

void solve()
{
    int in[] = {1,2,3};
    vector<Node*> trees = generateTree(in, 0, 2);
    for(Node* tree: trees)
    {
        printPreorder(tree);
        cout<<"\n";
    }
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();
   
   return 0;
}