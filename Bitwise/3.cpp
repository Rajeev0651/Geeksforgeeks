// Jai Shree Ram
// Find longest sequence of 1’s in binary representation with one flip
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void solve()
{
    int a;
    cin >> a;
    bitset<32> x = a;
    int toLeft[32];
    int toRight[32];
    memset(toRight, 0, sizeof(toRight));
    memset(toLeft, 0, sizeof(toLeft));
    toRight[31] = 0;
    toLeft[0] = 0;
    for (int i = 1; i < 32; i++)
    {
        if (x[i - 1] != 0)
            toRight[i] = toRight[i - 1] + 1;
    }
    for (int i = 30; i >= 0; i--)
    {
        if (x[i + 1] != 0)
            toLeft[i] = toLeft[i + 1] + 1;
    }
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        res = max(res, toLeft[i] + toRight[i]);
    }
    cout << res + 1;
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