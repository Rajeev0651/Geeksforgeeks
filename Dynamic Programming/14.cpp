// Jai Shree Ram
// Count the number of ways to tile the floor of size n x m using 1 x m size tiles
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)
#define MODULO_SEVEN 1000000007;

int dp[100002];

int fun(int N, int M)
{
    if (N < 0)
        return 0;
    if (N == M)
        return 2;
    if (N < M)
        return 1;
    int t1 = dp[N - 1] != -1 ? dp[N - 1] : fun(N - 1, M) % MODULO_SEVEN;
    int t2 = dp[N - M] != -1 ? dp[N - M] : fun(N - M, M) % MODULO_SEVEN;
    int res = 0;
    if (t1 > 0)
        res = t1;
    if (t2 > 0)
        res += t2;
    dp[N] = res % MODULO_SEVEN;
    return res % MODULO_SEVEN;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    int res = fun(N, M);
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