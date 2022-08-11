//Jai Shree Ram
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void solve(int q)
{
    int D,N,K,a,b,c;
    cin>>D>>N>>K;
    vector<tuple<int, int, int> > three;
    for(int i=0; i<N; i++)
    {
        cin>>a>>b>>c;
        three.push_back(make_tuple(a, b, c));
    }
    sort(three.begin(), three.end());
    int ans = -1,sum=0,left=K;
    for(int i=1; i<=D; i++)
    {   
        left = K;
        sum=0;
        for(int j=N-1; j>=0 && left>0; j--)
        {
            if((get<1>(three[j])<=i) && (i<=get<2>(three[j])))
            {
                left--;
                sum+=get<0>(three[j]);
            }
        }
        ans = max(ans,sum);
    }
    cout<<"Case #"<<q<<": "<<ans<<"\n";
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
}