//Jai Shree Ram
//
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

map<int, int> mp;

pair<int,int> search(int in[], int N)
{
    pair<int, int> p;
    int ans = INT_MAX, lc=INT_MAX;
    for(int i=0; i<N; i++)
    {
        int loc = mp.find(in[i])->second;
        if(loc<lc)
        {
            ans = in[i];
            lc = loc;
            p.first = ans;
            p.second = i;
        }
    }
    return p;
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

Node* compute(int in[], int N)
{
    pair<int,int> node_val = search(in, N);
    int val = node_val.first;
    int index = node_val.second;
    Node* tree = newNode(val);
    
    if(index>0)
        tree->left = compute(in, index);
    if(index<N-1)
        tree->right = compute(in+index+1, N-index-1);
    return tree;
}

void solve()
{
    int in[] = {4,8,10,12,14,20,22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    for(int i=0; i<7; i++) 
        mp.insert(make_pair(level[i], i));
    Node* tree = compute(in, 7);
    printLevelOrder(tree);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}