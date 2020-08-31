#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];
        int r=0,l=N-1,op=0;    
        while(r<=l)
        {
            if(A[r]==A[l])
            {
                r++;l--;
                continue;
            }
            if(A[r]<A[l])
            {
                A[r+1]+=A[r];r++;
                op++;
            }
            else
            {
                A[l-1]+=A[l];l--;
                op++;
            }
        }
        cout<<op<<"\n";
    }
    return 0;
}