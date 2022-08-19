// Jai Shree Ram
// Count number of ways to fill a “n x 4” grid using “1 x 4” tiles
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

long long dp[100] = {-1};

long long fun(int N)
{
    if (N <= 0)
        return 0;
    if (N == 4)
        return 2;
    if (N <= 3)
        return 1;
    long long t1 = (dp[N - 1] != -1) ? dp[N - 1] : fun(N - 1);
    long long t2 = (dp[N - 4] != -1) ? dp[N - 4] : fun(N - 4);
    long long res = t1 + t2;
    dp[N] = res;
    return res;
}

void solve()
{
    int N;
    cin >> N;
    ll res = fun(N);
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}