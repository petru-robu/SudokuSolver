#include <bits/stdc++.h>
#define NMAX 25
using namespace std;

class Sudoku
{
private:
  int** grid;
  int n;

  bool isPresentInCol(int col, int num);
  bool isPresentInRow(int row, int num);
  bool isPresentInBox(int brow, int bcol, int num);
  bool isValidPlace(int row, int col, int num);
  bool findEmptyPlace(int &row, int &col);

public:
  Sudoku(int size, int **v);
  ~Sudoku();
  bool solve();
  void printSudoku();

};

