// Jai Shree Ram
// Find the total number of setbits in the numbers from 1 to N
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void solve()
{
    int N, res = 0;
    cin >> N;
    N += 1;
    for (int i = 0; i <= 32; i++)
    {
        int k = pow(2, i);
        int rem = N % k;
        int a = N / k;
        if (a % 2 == 1)
            res += rem;
        a = (a / 2) * k;
        res += a;
    }
    cout << res;
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