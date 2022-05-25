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

Sudoku::Sudoku(int size, int **v)
{
  n=size;
  grid=v;
}

Sudoku::~Sudoku()
{
  for(int i=0; i<n; i++)
      delete grid[i];
  delete grid;
}

bool Sudoku::isPresentInCol(int col, int num)
{
   for (int row = 0; row < n; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool Sudoku::isPresentInRow(int row, int num)
{
   for (int col = 0; col < n; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool Sudoku::isPresentInBox(int brow, int bcol, int num)
{
   for (int row=0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+brow][col+bcol] == num)
            return true;
   return false;
}
bool Sudoku::findEmptyPlace(int &row, int &col)
{
   for (row = 0; row < n; row++)
      for (col = 0; col < n; col++)
         if (grid[row][col] == 0)
            return true;
   return false;
}
bool Sudoku::isValidPlace(int row, int col, int num)
{
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,col - col%3, num);
}

bool Sudoku::solve()
{
   int row, col;
   if (!findEmptyPlace(row, col))
      return true;
   for (int num = 1; num <= 9; num++)
   {
      if (isValidPlace(row, col, num))
      {
         grid[row][col] = num;
         if (solve())
            return true;
         grid[row][col] = 0;
      }
   }
   return false;
}

void Sudoku::printSudoku()
{
   cout << "\n\n";
   for (int row=0; row<n; row++){
      for (int col=0; col<n; col++)
      {
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<n; i++)
            cout << "---";
      }
      cout << '\n';
   }
}
