// Jai Shree Ram
// Smallest sum contiguous subarray
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

void solve()
{
    int N, res=INT_MAX;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        res = min(res, A[i]);
    }
    int left[N];
    int right[N];
    left[N - 1] = A[N - 1];
    right[0] = A[0];
    for (int i = N - 2; i >= 0; i--)
    {
        if (A[i] + left[i + 1] < A[i])
            left[i] = A[i] + left[i + 1];
        else
            left[i] = A[i];
    }
    for (int i = 1; i < N; i++)
    {
        int r = A[i] + right[i - 1];
        if (A[i] > r)
            right[i] = r;
        else
            right[i] = A[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        res = min(res, right[i] + left[i + 1]);
    }
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