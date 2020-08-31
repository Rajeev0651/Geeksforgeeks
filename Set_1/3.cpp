#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        long int N,Q,r=0,l=0;
        cin>>N;
        int A[1001],B[1001];
        A[0] = 0;
        for(int i=1; i<=N; i++)
            cin>>A[i];
        int sum=0;
        for(int i=1; i<=N; i++)
        {
            B[i] = B[i-1] + A[i];
        }
        cin>>Q;int k=Q;
        int R[1001],L[1001];
        while(Q--)
        {
            cin>>L[l++]>>R[r++];
        }
        l=0;r=0;
        while(k--)
        {
            cout<<(B[R[r++]]-B[L[l++]-1])<<" ";
        }
        cout<<"\n";
    }
    return 0;
}