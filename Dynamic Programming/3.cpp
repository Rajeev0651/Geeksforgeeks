// Jai Shree Ram
// Probability of reaching a point with 2 or 3 steps at a time
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

float dp[1000000]={0.0};

float fun(int N, float P)
{
    if (N == 0)
        return 1;
    if (N < 0)
        return 0;
    float res = 0;
    res = (dp[N - 2] != 0 ? dp[N - 2] : fun(N - 2, P) * P) + (dp[N - 3] != 0 ? dp[N - 3] : fun(N - 3, P) * (1 - P));
    dp[N] = res;
    return res;
}

void solve()
{
    int N;
    float P;
    cin >> N >> P;
    float prob = fun(N, P);
    cout << prob << "\n";
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