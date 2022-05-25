#include <bits/stdc++.h>
#include "sudoku.h"
using namespace std;

int main()
{
  const int n = 9;
  int **v = new int*[n];
  for(int i=0; i<n; i++)
    v[i] = new int[n];

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin>>v[i][j];

  Sudoku sud(n, v);

  sud.solve();
  sud.printSudoku();

}
