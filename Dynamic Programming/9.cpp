// Jai Shree Ram
// Remove array end element to maximize the sum of product
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

int dp[1000][100];

int fun(int A[], int s, int N, int completed)
{
    if (s >= N)
        return 0;
    int res = -1, r1, r2;
    if (dp[s + 1][N] != -1)
        r1 = dp[s + 1][N];
    else
        r1 = fun(A, s + 1, N, completed + 1) + (A[s] * (completed + 1));

    if (dp[s][N - 1] != -1)
        r2 = dp[s][N - 1];
    else
        r2 = fun(A, s, N - 1, completed + 1) + (A[N - 1] * (completed + 1));
    res = max(r1, r2);
    return res;
}

void solve()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int res = fun(A, 0, N, 0);
    cout << res << "\n";
    // Greedy approach
    // int removed = 0, sum = 0;
    // int i = 0, j = N - 1;
    // while (i <= j)
    // {
    //     if (A[i] < A[j])
    //         sum += (A[i++] * (removed++ + 1));
    //     else
    //         sum += (A[j--] * (removed++ + 1));
    // }
    // cout << sum << "\n";
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