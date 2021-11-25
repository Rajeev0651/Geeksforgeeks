#include<bits/stdc++.h>
using namespace std;
int b(int n, int k)
{
    int res = 1;
    if(k>(n-k))
        k = n-k;
    for(int i=0; i<k ;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }   
    return res; 
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,Z,M;
        cin>>Z>>N>>M;
        long long int val=1;
        val = b(Z, M);
        val = (val*(M*(M+1))/2)%1000000007;
        cout<<val<<"\n";
    }
    return 0;
}