// Jai Shree Ram
// Count all possible paths from top left to bottom right of a mXn matrix
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

int M, N;
long long dp[102][102];

ll fun(int x, int y)
{
    if (x == M && y == N)
        return 1;
    if (x > M || y > N)
        return 0;
    long long r = (dp[x + 1][y] != -1) ? dp[x + 1][y] : fun(x + 1, y);
    long long d = (dp[x][y + 1] != -1) ? dp[x][y + 1] : fun(x, y + 1);
    long long res = 0;
    if (r > 0)
        res = r;
    if (d > 0)
        res += d;
    dp[x][y] = res % 1000000007;
    return res % 1000000007;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> M >> N;
    ll res = fun(1, 1);
    cout << res << "\n";
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