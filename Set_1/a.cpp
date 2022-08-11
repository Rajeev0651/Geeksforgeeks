<<<<<<< HEAD
//Jai Shree Ram
// Directed graph BFS
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void solve(int q)
{
    ll N,sum=0;
    cin>>N;
    string S;
    ll A[N],B[N];
    memset(A, 0, sizeof(ll)*N);
    memset(B, 0, sizeof(ll)*N);
    cin>>S;
    ll prev=-1;
    for(ll i=0; i<N; i++)
    {
        if(S[i]=='0')
        {
            A[i] = prev;
        }
        else{
            prev = i+1;
        }
    }
    prev = -1;
    for(ll i=N-1; i>=0; i--)
    {
        if(S[i]=='0')
        {
            B[i] = prev;
        }
        else{
            prev = i+1;
        }
    }
    for(ll i=0; i<N; i++)
    {
        if(S[i]=='0')
        {
            if(A[i]==-1)
                sum+= B[i]-i-1;
            else if(B[i]==-1)
                sum+= i-A[i]+1;
            else 
                sum+= min(i-A[i]+1, B[i]-i-1);
        }
    }
    cout<<"Case #"<<q<<": "<<sum<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int T;
   cin >> T;
   int q = 1;
   while (T--)
   {
     solve(q++);
   }
   return 0;
=======
//Jai Shree Ram
// Directed graph BFS
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void solve(int q)
{
    ll N,sum=0;
    cin>>N;
    string S;
    ll A[N],B[N];
    memset(A, 0, sizeof(ll)*N);
    memset(B, 0, sizeof(ll)*N);
    cin>>S;
    ll prev=-1;
    for(ll i=0; i<N; i++)
    {
        if(S[i]=='0')
        {
            A[i] = prev;
        }
        else{
            prev = i+1;
        }
    }
    prev = -1;
    for(ll i=N-1; i>=0; i--)
    {
        if(S[i]=='0')
        {
            B[i] = prev;
        }
        else{
            prev = i+1;
        }
    }
    for(ll i=0; i<N; i++)
    {
        if(S[i]=='0')
        {
            if(A[i]==-1)
                sum+= B[i]-i-1;
            else if(B[i]==-1)
                sum+= i-A[i]+1;
            else 
                sum+= min(i-A[i]+1, B[i]-i-1);
        }
    }
    cout<<"Case #"<<q<<": "<<sum<<"\n";
}

int main()
{
   //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int T;
   cin >> T;
   int q = 1;
   while (T--)
   {
     solve(q++);
   }
   return 0;
>>>>>>> 2a80f9d26c7e29e683e9384276aa9d2d416b591c
}