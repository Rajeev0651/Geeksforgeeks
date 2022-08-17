// Jai Shree Ram
//Value of continuous floor function : F(x) = F(floor(x/2)) + x
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

int dp[1000000] = {};

int fun(int K)
{
    if (K == 0)
        return 0;
    if (dp[K] != 0)
        return dp[K];
    int res = 0;
    res += K + fun(K / 2);
    dp[K] = res;
    return res;
}

void solve()
{
    int N, res = 0;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
    {
        res = A[i] + fun(A[i] / 2);
        cout << res << " ";
    }
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