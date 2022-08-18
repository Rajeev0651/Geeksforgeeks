// Jai Shree Ram
// Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

int curMax = 1;
int dp[1000000] = {0};

int fun(int A[], int N)
{
    if (N == 1)
        return 1;
    int len = 1, t;
    for (int i = 1; i < N; i++)
    {
        if (dp[i] != 0)
            t = dp[i];
        else
            t = fun(A, i);
        if ((A[i - 1] < A[N - 1]) && (t + 1 > len))
            len = t + 1;
    }
    if (len > curMax)
        curMax = len;
    return len;
}

void solve()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int res = fun(A, N);
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