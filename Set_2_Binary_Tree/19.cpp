//Jai Shree Ram
//https://www.geeksforgeeks.org/number-of-binary-trees-for-given-preorder-sequence-length/
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

int calculate(int N)
{
    int ans[1000];
    memset(ans, 0, sizeof(ans));
    ans[0] = ans[1] = 1;
    for(int i=2; i<=N; i++)
    {
        int k = i;
        for(int j=0; j<i; j++)
        {
            k--;
            ans[i] += (ans[j]*ans[k]);
        }
    }
    return ans[N];
}

void solve()
{
    int N;
    cin>>N;
    cout<<calculate(N)<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();

   return 0;
}