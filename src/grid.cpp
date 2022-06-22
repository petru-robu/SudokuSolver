#include "../include/grid.h"

Grid::Grid()
{
  grid = new Cell*[GRID_S];
  for(int i=0; i<GRID_S; i++)
    grid[i] = new Cell[GRID_S];

  solved = false;
}

Grid::~Grid()
{
  for(int i=0; i<GRID_S; i++)
      delete grid[i];
  delete grid;
  std::cout<<"Destructor apelat!\n";
}

bool Grid::isPresentInCol(int col, int num)
{
   for (int row = 0; row < GRID_S; row++)
      if (grid[row][col].get_val() == num)
         return true;
   return false;
}
bool Grid::isPresentInRow(int row, int num)
{
   for (int col = 0; col < GRID_S; col++)
      if (grid[row][col].get_val() == num)
         return true;
   return false;
}
bool Grid::isPresentInBox(int brow, int bcol, int num)
{
   for (int row=0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+brow][col+bcol].get_val() == num)
            return true;
   return false;
}
bool Grid::findEmptyPlace(int &row, int &col)
{
   for (row = 0; row < GRID_S; row++)
      for (col = 0; col < GRID_S; col++)
         if (grid[row][col].get_val() == 0)
            return true;
   return false;
}
bool Grid::isValidPlace(int row, int col, int num)
{
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,col - col%3, num);
}

bool Grid::solveUtil()
{
   int row, col;
   if (!findEmptyPlace(row, col))
      return true;
   for (int num = 1; num <= 9; num++)
   {
      if (isValidPlace(row, col, num))
      {
         grid[row][col].set_val(num);
         if (solveUtil())
            return true;

         grid[row][col].set_val(0);
      }
   }
   return false;
}

bool Grid::solve()
{
  if(solveUtil())
  {
    solved=true;
    return true;
  }
  else
  {
    solved=false;
    return false;
  }

}
void Grid::set_state(bool a)
{
  solved=a;
}

void Grid::set_cell(int c1, int c2, int val)
{
  grid[c1][c2].set_val(val);
}

bool Grid::get_state()
{
  return solved;
}

int Grid::get_cell(int c1, int c2)
{
  return grid[c1][c2].get_val();
}

void Grid::display(sf::RenderWindow &window, sf::Font font, int marg, int cell_size)
{
  Cell cnt;
  for (int i=0; i<GRID_S; i++)
  {
    int c2 = marg + i*cell_size;
    for (int j=0; j<GRID_S; j++)
    {
      int c1 = marg + j*cell_size + 1;
      cnt.set_val(grid[i][j].get_val());
      cnt.display(window, font, c1, c2, cell_size);
    }
  }

}
