#include <bits/stdc++.h>
using namespace std;
int M = 8, N = 8;
void flood_fill(int A[8][8], int x, int y, int val)
{
  A[x][y] = val;
  if ((x + 1) < 8)
    flood_fill(A, x + 1, y, val);
  if ((x - 1) >= 0)
    flood_fill(A, x - 1, y, val);
  if ((y + 1) < 8)
    flood_fill(A, x, y + 1, val);
  if ((y - 1) >= 0)
    flood_fill(A, x, y - 1, val);
}
int main()
{
  int screen[8][8] = {
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 1, 1, 0, 1, 1},
      {1, 2, 2, 2, 2, 0, 1, 0},
      {1, 1, 1, 2, 2, 0, 1, 0},
      {1, 1, 1, 2, 2, 2, 2, 0},
      {1, 1, 1, 1, 1, 2, 1, 1},
      {1, 1, 1, 1, 1, 2, 2, 1},
  };
  int x, y, val;
  cin >> x >> y >> val;
  flood_fill(screen, x, y, val);
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
      cout << screen[i][j] << " ";
    cout << "\n";
  }
  return 0;
}