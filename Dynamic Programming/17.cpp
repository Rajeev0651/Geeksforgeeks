// Jai Shree Ram
// Counting pairs when a person can form pair with at most one
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)
#define MODULO_SEVEN 1000000007;

int dp[1000000];

int fun(int N)
{
    if (N <= 0)
        return 0;
    if (N <= 2)
        return N;
    int t1 = dp[N - 1] != -1 ? dp[N - 1] : fun(N - 1);
    int t2 = dp[N - 2] != -1 ? dp[N - 2] : fun(N - 2) * (N - 1);
    int res = t1 + t2;
    dp[N] = res;
    return res;
}

void solve()
{
    int N;
    cin >> N;
    int res = fun(N);
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