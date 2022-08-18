// Jai Shree Ram
 //Longest alternating (positive and negative) subarray starting at every index
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void solve()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int ans[N] = {0};
    ans[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (A[i] / abs(A[i]) == A[i + 1] / abs(A[i + 1]))
            ans[i] = 1;
        else
            ans[i] = ans[i + 1] + 1;
    }
    for(int i=0; i<N; i++)
        cout<<ans[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}