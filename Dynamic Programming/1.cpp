// Jai Shree Ram
//Different ways to sum n using numbers greater than or equal to m
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

int index[100000];

int dp(int n, int m)
{
    if (m > n || n <= 0)
        return 0;
    if (index[n] != -1)
        return index[n];
    int res = dp(n - 1, m) + 1;
    index[n] = res;
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int res = dp(n, m);
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(index, -1, sizeof(index));
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}