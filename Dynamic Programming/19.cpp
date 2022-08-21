// Jai Shree Ram
// Count ways to reach the nth stair using step 1, 2 or 3
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)
#define MODULO_SEVEN 1000000007;

int dp[100005];

int fun(int N)
{
    if (N < 0)
        return -1;
    if (N <= 3)
        return N;
    int t1 = dp[N - 1] != -1 ? dp[N - 1] : fun(N - 1);
    int t2 = dp[N - 2] != -1 ? dp[N - 2] : fun(N - 2);
    int t3 = dp[N - 3] != -1 ? dp[N - 3] : fun(N - 3);
    int res = 0;
    if (t1 >= 0)
        res = t1;
    if (t2 >= 0)
        res += t2 % MODULO_SEVEN;
    if (t3 >= 0)
        res += t3 % MODULO_SEVEN;
    dp[N] = res % MODULO_SEVEN;
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