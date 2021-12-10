//Jai Shree Ram
//https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
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

pair<string, string> search(string S)
{
    pair<string, string> ans("","");
    stack<char> st;
    for(int i=0; i<S.length(); i++)
    {
        if(S[i]=='(')
            st.push('(');
        else if(S[i]==')'){
            if(st.size()==1)
            {
                ans.first = S.substr(2, i-2);
                if(i+2<S.length())
                    ans.second = S.substr(i+2, S.length()-i-3);
                return ans;
            }
            else  
                st.pop();
        }
    }
    return ans;
}

Node* compute(string S)
{
    Node* node = newNode(S.front()-'0');
    stack<char> st;
    pair<string, string> s = search(S);
    if(s.first!="")
        node->left = compute(s.first);
    if(s.second!="")
        node->right = compute(s.second);
    return node;
}

void solve()
{
    string S = "4(2(3)(1))(6(5))";
    Node* Parent_node = compute(S);
    printLevelOrder(Parent_node);
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}