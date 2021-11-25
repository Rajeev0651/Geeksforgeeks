#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int optimal(vector<int> A, int i, int j)
{
  if (j == i + 1)
    return max(A[i], A[j]);
  if (i == j)
    return A[i];
  if (dp[i][j] != 0)
  return dp[i][j];
  dp[i][j] = max(A[i] + min(optimal(A, i + 2, j), optimal(A, i + 1, j - 1)),
                 A[j] + min(optimal(A, i + 1, j - 1), optimal(A, i, j - 2)));
  return dp[0][A.size() - 1];
}
int main()
{
  int N, a;
  cin >> N;
  vector<int> A;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    A.push_back(a);
  }
  cout << optimal(A, 0, A.size()-1);
  return 0;
}