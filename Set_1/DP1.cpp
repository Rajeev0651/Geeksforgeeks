#include <bits/stdc++.h>
using namespace std;
int ugly(int N)
{
  int ugly[100001];
  ugly[0] = 1;
  int a = 0, b = 0, c = 0;
  int next_ugly_two = ugly[a] * 2, next_ugly_three = ugly[b] * 3, next_ugly_five = ugly[c] * 5;
  for (int i = 1; i < N; i++)
  {
    int next_val = min(next_ugly_two, min(next_ugly_three, next_ugly_five));
    ugly[i] = next_val;
    if (next_val == next_ugly_two)
    {
      next_ugly_two = ugly[++a] * 2;
    }
    if (next_val == next_ugly_three)
    {
      next_ugly_three = ugly[++b] * 3;
    }
    if (next_val == next_ugly_five)
    {
      next_ugly_five = ugly[++c] * 5;
    }
    cout << ugly[i] << " ";
  }
  return ugly[N - 1];
}
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, ans;
    cin >> N;
    if (N != 0)
      cout << "1 ";
    ans = ugly(N);
  }
  return 0;
}