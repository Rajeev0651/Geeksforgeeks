// Jai Shree Ram
// Counts paths from a point to reach Origin
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)
#define MODULO_SEVEN 1000000007;

// vector<ll> row(503, -1);
// vector<vector<ll>> dp(503, row);
l dp[502][502];

l fun(int N, int M)
{
    if (N == 0 && M == 0)
        return 1;
    if (N < 0 || M < 0)
        return 0;
    l left = ((M-1 >=0 && dp[N][M - 1] != -1) ? dp[N][M - 1] : fun(N, M - 1));
    l right = ((N-1 >=0 && dp[N - 1][M] != -1) ? dp[N - 1][M] : fun(N - 1, M));
    l res = 0;
    if (left > 0)
        res = (res + left) % MODULO_SEVEN;
    if (right > 0)
        res = (res + right) % MODULO_SEVEN;
    dp[N][M] = res;
    return res;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    l res = fun(N, M);
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dp, -1 , sizeof(dp));
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}