// Jai Shree Ram
// Unique paths in a Grid with Obstacles
#include <bits/stdc++.h>
using namespace std;

#define l long
#define ll long long
#define FOR(i, a, b) for (auto i = a; i <= b; i++)
#define FOREV(i, a, b) for (auto i = a; i >= b; i--)

int N, M;
int A[100][100];
int dp[100][100];

int fun(int X, int Y)
{
    if (X > M || Y > N || A[X][Y] == 1)
        return 0;
    if (X == M && Y == N)
        return 1;
    int res = 0;
    int go_up = (dp[X + 1][Y] != -1) ? dp[X + 1][Y] : fun(X + 1, Y);
    int go_right = (dp[X][Y + 1] != -1) ? dp[X][Y + 1] : fun(X, Y + 1);
    if (go_up > 0)
        res += go_up;
    if (go_right > 0)
        res += go_right;
    dp[X][Y] = res;
    return res;
}

void solve()
{
    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];
    int res = fun(1, 1);
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(A, 0, sizeof(A));
    memset(dp, -1, sizeof(dp));
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}