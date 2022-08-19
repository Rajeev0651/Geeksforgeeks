// Jai Shree Ram
// Count number of ways to cover a distance
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)
#define MODULO_SEVEN 1000000007;

long long dp[100002];

long long fun(int N)
{
    if (N == 1)
        return 1;
    if (N == 2)
        return 2;
    if (N == 3)
        return 4;
    long long res = 0;
    if (N == 0)
        return 0;
    if (N < 0)
        return -1;
    long long t1 = (dp[N - 1] != -1) ? dp[N - 1] : fun(N - 1);
    long long t2 = (dp[N - 2] != -1) ? dp[N - 2] : fun(N - 2);
    long long t3 = (dp[N - 3] != -1) ? dp[N - 3] : fun(N - 3);
    if (t1 > 0)
        res = (res + t1) % MODULO_SEVEN;
    if (t2 > 0)
        res = (res + t2) % MODULO_SEVEN;
    if (t3 > 0)
        res = (res + t3) % MODULO_SEVEN;
    dp[N] = res % MODULO_SEVEN;
    return res;
}

void solve()
{
    int N;
    cin >> N;
    long long res = fun(N);
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