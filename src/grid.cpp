#include "../include/grid.h"

Grid::Grid()
{
  grid = new Cell*[GRID_S];
  for(int i=0; i<GRID_S; i++)
    grid[i] = new Cell[GRID_S];

  solved = false;
  selectedCell = NULL;
}

Grid::~Grid()
{
  for(int i=0; i<GRID_S; i++)
      delete[] grid[i];
  delete grid;
  delete selectedCell;
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

Cell& Grid::get_cell(int c1, int c2)
{
  return grid[c1][c2];
}
void Grid::prepareDisplay()
{
   for(int i=0; i<GRID_S; i++)
      for(int j=0; j<GRID_S; j++)
         grid[i][j].set_color(sf::Color::Black);
}

void Grid::display(sf::RenderWindow &window, sf::Font font, int marg)
{
  Cell cnt;
  int cell_size = cnt.get_cell_size();

  for (int i=0; i<GRID_S; i++)
  {
    int c2 = marg + i*cell_size;
    for (int j=0; j<GRID_S; j++)
    {
      int c1 = marg + j*cell_size + 1;
      grid[i][j].display(window, font, c1, c2);
    }
  }
}

void Grid::manageCellsOnClick(sf::RenderWindow &window, sf::Vector2f &mouse)
{
   for(int i=0; i<GRID_S; i++)
       for(int j=0; j<GRID_S; j++)
            grid[i][j].set_view(true);
   selectedCell = NULL;
   for(int i=0; i<GRID_S; i++)
     for(int j=0; j<GRID_S; j++)
     {
      if(grid[i][j].selected(mouse))
         {
            selectedCell = &grid[i][j];
            std::cout<<i<<' '<<j<<' '<<grid[i][j].get_val()<<'\n'; 
            std::cout<<selectedCell->get_val()<<'\n';
            grid[i][j].set_view(false);
         }
     }             
}  

void Grid::manageCellsOnHover(sf::RenderWindow &window, sf::Vector2f &mouse)
{
   for(int i=0; i<GRID_S; i++)
     for(int j=0; j<GRID_S; j++)
     {
      if(grid[i][j].selected(mouse))
         grid[i][j].set_color(sf::Color::Red);
      else  
         grid[i][j].set_color(sf::Color::Black);
     }             
} 

void Grid::manageCellsOnInput(sf::RenderWindow &window, sf::Vector2f &mouse)
{
      int x=0;
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
		{
			x=0;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
		{
			x=1;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
		{
			x=2;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
		{
			x=3;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
		{
			x=4;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
		{
			x=5;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
		{
			x=6;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
		{
			x=7;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
		{
			x=8;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
		{
			x=9;
		}
      std::cout<<x<<'\n';
      selectedCell->set_val(x);
      selectedCell->set_view(true);
      selectedCell = NULL;           
} 

void Grid::clear()
{
   for(int i=0; i<GRID_S; i++)
       for(int j=0; j<GRID_S; j++)
         grid[i][j].set_val(0);
}
