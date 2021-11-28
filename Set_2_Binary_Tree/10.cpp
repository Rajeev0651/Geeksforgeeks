//Jai Shree Ram
//https://www.geeksforgeeks.org/level-order-traversal-direction-change-every-two-levels/
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
    if(root==NULL)
        return;

    queue<Node*> Qu;
    stack<Node*> st;
    Qu.push(root);
    bool LeftToRight = true;
    int c = 0;
    while (!Qu.empty())
    {

        int qsize = Qu.size();
        c++;

        for(int i=0; i<qsize; i++)
        {
            if(!LeftToRight)
                st.push(Qu.front());
            else
            cout<<Qu.front()->data<<" ";
        if(Qu.front()->left)
        {
            Qu.push(Qu.front()->left);
        }
            
        if(Qu.front()->right)
        {
            Qu.push(Qu.front()->right);
        }
        Qu.pop();
        }
        if(!LeftToRight)
        {
            while (!st.empty())
            {
                cout<<st.top()->data<<" ";
                st.pop();
            }
            
        }
        if(c==2)
        {
            LeftToRight = !LeftToRight;
            c=0;
        }
        cout<<"\n";
    }
}

void solve()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(1);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(2);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(2);
    root->left->right->left->left = new Node(16);
    root->left->right->left->right = new Node(17);
    root->right->left->right->left = new Node(18);
    root->right->right->left->right = new Node(19);

    printLevelOrder(root);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
   
   return 0;
}