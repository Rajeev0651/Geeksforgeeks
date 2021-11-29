//Jai Shree Ram
//https://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/
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
    Node (char data)
    {
        this->data = data;
        left = right = NULL;
    }
};

vector<Node*> ans;
void printLevelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
 
    q.push(root);
 
    while (q.empty() == false) {
        Node* node = q.front();
        cout << node->data << " ";
        ans.push_back(node);
        q.pop();
 
        if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
    }
}

void solve()
{
    struct Node *root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');
    root->left->left->left = new Node('h');
    root->left->left->right = new Node('i');
    root->left->right->left = new Node('j');
    root->left->right->right = new Node('k');
    root->right->left->left = new Node('l');
    root->right->left->right = new Node('m');
    root->right->right->left = new Node('n');
    root->right->right->right = new Node('o');
    printLevelOrder(root);
    int count = 1;
    while (count*2 <= ans.size()-1)
    {
        int left = count, right = count*2;
        while (left<right)
        {
            //cout<<ans[left++]->data<<" "<<ans[right--]->data<<" ";
            swap(ans[left]->data, ans[right]->data);
            left++;right--;
        }
        count = (count*2 + 1)*2 +1;
    }
    cout<<"\n";
    printLevelOrder(root);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
   
   return 0;
}