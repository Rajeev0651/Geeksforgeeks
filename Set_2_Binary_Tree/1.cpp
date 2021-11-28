//Jai Shree Ram
//https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--) 

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

int find(int array[], int val, int N)
{
    for(int i=0; i<N; i++)
    {
        if(array[i] == val)
        {
            return i;
        }
            
    }
    return -1;
}

void printPostOrder(int in[], int pre[], int N)
{
    int val = find(in, pre[0], N);
    if(val!=0)
    {
        printPostOrder(in, pre+1, val);  
    }
    
    if(val!=N-1)
    {
        printPostOrder(in+val+1, pre+val+1, N-val-1);
    }
    cout<<pre[0]<<" ";
}

void solve()
{
   int in[] = {4,2,5,1,3,6};
   int pre[] = {1,2,4,5,3,6};
   printPostOrder(in, pre, 6);cout<<endl;
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   solve();
   return 0;
}