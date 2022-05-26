#include <bits/stdc++.h>
#include "sudoku.h"
using namespace std;

ifstream fin("sudoku.in");

int main()
{
  const int n = 9;
  int **v = new int*[n];
  for(int i=0; i<n; i++)
    v[i] = new int[n];

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      fin>>v[i][j];

  Sudoku sud(n, v);

  sud.solve();
  sud.printSudoku();

}
