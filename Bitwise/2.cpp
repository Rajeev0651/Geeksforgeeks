// Jai Shree Ram
//Find Duplicates of array using bit array
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void solve()
{
    int N, x;
    cin >> N;
    int pos[4000], A[N];
    memset(pos, 0, sizeof(pos));
    bitset<32> a = pos[1];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
    {
        int x = A[i];
        int k = x / 32;
        int p = pos[k];
        int rem = x % 32;
        if (p & (1 << (31 - rem)))
            cout << x << " ";
        else
        {
            p = p | (1 << (31 - rem));
            pos[k] = p;
        }
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