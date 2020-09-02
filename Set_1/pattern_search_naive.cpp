#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s, p;
  cin >> s >> p;
  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    for (int j = i + 1; j < s.length() - 1; j++)
    {
      if (p == s.substr(i, j - i + 1))
        count++;
    }
  }
  cout << count << "\n";
  return 0;
}