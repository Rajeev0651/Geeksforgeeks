// Jai Shree Ram
// Number of n-digits non-decreasing integers
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

long long dp[1000][10];

int fun(int N, int s)
{
    if (s > 9)
        return 0;
    if (N == 1)
        return 10 - s;
    long long res = 0, t;
    for (int i = s; i <= 9; i++, s++)
    {

        if (dp[N - 1][s] != -1)
            t = dp[N - 1][s];

        else
        {
            t = fun(N - 1, s);
            dp[N - 1][s] = t;
        }
        if (t > 0)
            res += t;
    }
    return res;
}

void solve()
{
    int N;
    cin >> N;
    int res = fun(N, 0);
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