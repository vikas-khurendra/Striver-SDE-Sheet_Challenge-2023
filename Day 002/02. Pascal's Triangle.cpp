// Key Point: for finding coefficient for each row we have to use
// formula coef = coef * (i - j) / j. And also we must initialize
// for loop with 1 but not with 0 to avoid 1/0 = infinity problem.

#include <bits/stdc++.h>

using namespace std;

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> v;
  for(int i = 1; i <= n; i++)
  {
      long long int coef = 1;
      vector<long long int> temp;
      for(int j = 1; j <= i; j++)
      {
          temp.push_back(coef);
          coef = coef * (i - j) / j;
      }
      v.push_back(temp);
  }
  return v;
}