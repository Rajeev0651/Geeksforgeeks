// Jai Shree Ram
// Ways to sum to N using array elements with repetition allowed
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

int dp[1000] = {0};

long long fun(int A[], int N, int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    long long res = 0, t;
    for (int i = 0; i < N; i++)
    {
        if (sum - A[i] >= 0 && dp[sum - A[i]] != 0)
            t = dp[sum - A[i]];
        else
            t = fun(A, N, sum - A[i]);
        dp[sum - A[i]] = t;
        res += t;
    }
    return res;
}

void solve()
{
    long long N, res, sum;
    cin >> N >> sum;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    res = fun(A, N, sum);
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //memset(dp, -1, sizeof(dp));
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}