#include "../include/grid.h"

Grid::Grid()
{
  grid = new Cell*[GRID_S];
  for(int i=0; i<GRID_S; i++)
    grid[i] = new Cell[GRID_S];

  solved = false;
  errors=false;
  selectedCell = NULL;
}

Grid::~Grid()
{
  for(int i=0; i<GRID_S; i++)
      delete[] grid[i];
  delete grid;
  delete selectedCell;
  std::cout<<"Destructor apelat pentru Grid!\n";
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


void Grid::MarkConflicting()
{ 
   errors = false;

   for(int col=0; col<GRID_S; col++)
   {
      for(int i=0; i<GRID_S; i++)
      {
         for(int j=0; j<GRID_S; j++)
         {
            if(grid[i][col].get_val()==grid[j][col].get_val() && grid[i][col].get_val()!=0 && j!=i)
            {
               grid[i][col].text_color(sf::Color::Red);
               grid[j][col].text_color(sf::Color::Red);
               errors=true;
            }     
         } 
      }
   }


   for(int row=0; row<GRID_S; row++)
   {
      for(int i=0; i<GRID_S; i++)
      {
         for(int j=0; j<GRID_S; j++)
         {
            if(grid[row][i].get_val()==grid[row][j].get_val() && grid[row][i].get_val()!=0 && j!=i)
            {
               grid[row][i].text_color(sf::Color::Red);
               grid[row][j].text_color(sf::Color::Red);
               errors=true;
            }     
         } 
      }
   }



   for(int brow=0; brow<GRID_S; brow+=3)
      for(int bcol=0; bcol<GRID_S; bcol+=3)
      {
         for(int row = 0; row < 3; row++)
            for(int col = 0; col < 3; col++)
               for(int row1 = 0; row1 < 3; row1++)
                  for(int col1 = 0; col1 < 3; col1++)
                     if(grid[row+brow][col+bcol].get_val()==grid[row1+brow][col1+bcol].get_val()&& grid[row+brow][col+bcol].get_val()!=0 && (row+brow!=row1+brow||col+bcol!=col1+bcol))
                     {
                        grid[row+brow][col+bcol].text_color(sf::Color::Red);
                        grid[row1+brow][col1+bcol].text_color(sf::Color::Red);
                        errors=true;
                     }
      }
}

void Grid::CheckSolved()
{
   if(errors)
   {
      solved = false;
      return;
   }
   for(int i=0; i<GRID_S; i++)
       for(int j=0; j<GRID_S; j++)
         if(grid[i][j].get_val()<1 || grid[i][j].get_val()>9) 
         {
            solved = false;
            return;
         }

   solved=true;
}         

void Grid::clear()
{
   for(int i=0; i<GRID_S; i++)
       for(int j=0; j<GRID_S; j++)
       {
         grid[i][j].set_val(0);
         grid[i][j].set_fixed(0);
         Init();
       }    
}

void Grid::loadEasy()
{
   clear();
   set_cellfixed(1,1,2);
   set_cellfixed(1,2,6);
   set_cellfixed(1,3,3);
   set_cellfixed(1,4,1);
   set_cellfixed(1,5,4);
   set_cellfixed(1,6,0);
   set_cellfixed(1,7,7);
   set_cellfixed(1,8,5);
   set_cellfixed(1,9,8);
   set_cellfixed(2,1,0);
   set_cellfixed(2,2,0);
   set_cellfixed(2,3,0);
   set_cellfixed(2,4,0);
   set_cellfixed(2,5,8);
   set_cellfixed(2,6,5);
   set_cellfixed(2,7,3);
   set_cellfixed(2,8,0);
   set_cellfixed(2,9,9);
   set_cellfixed(3,1,9);
   set_cellfixed(3,2,8);
   set_cellfixed(3,3,0);
   set_cellfixed(3,4,6);
   set_cellfixed(3,5,0);
   set_cellfixed(3,6,7);
   set_cellfixed(3,7,1);
   set_cellfixed(3,8,2);
   set_cellfixed(3,9,0);
   set_cellfixed(4,1,0);
   set_cellfixed(4,2,7);
   set_cellfixed(4,3,8);
   set_cellfixed(4,4,9);
   set_cellfixed(4,5,1);
   set_cellfixed(4,6,0);
   set_cellfixed(4,7,5);
   set_cellfixed(4,8,4);
   set_cellfixed(4,9,0);
   set_cellfixed(5,1,1);
   set_cellfixed(5,2,2);
   set_cellfixed(5,3,0);
   set_cellfixed(5,4,5);
   set_cellfixed(5,5,6);
   set_cellfixed(5,6,4);
   set_cellfixed(5,7,0);
   set_cellfixed(5,8,7);
   set_cellfixed(5,9,3);
   set_cellfixed(6,1,4);
   set_cellfixed(6,2,0);
   set_cellfixed(6,3,6);
   set_cellfixed(6,4,3);
   set_cellfixed(6,5,7);
   set_cellfixed(6,6,0);
   set_cellfixed(6,7,0);
   set_cellfixed(6,8,9);
   set_cellfixed(6,9,1);
   set_cellfixed(7,1,0);
   set_cellfixed(7,2,3);
   set_cellfixed(7,3,2);
   set_cellfixed(7,4,4);
   set_cellfixed(7,5,0);
   set_cellfixed(7,6,1);
   set_cellfixed(7,7,9);
   set_cellfixed(7,8,8);
   set_cellfixed(7,9,7);
   set_cellfixed(8,1,8);
   set_cellfixed(8,2,9);
   set_cellfixed(8,3,1);
   set_cellfixed(8,4,7);
   set_cellfixed(8,5,0);
   set_cellfixed(8,6,0);
   set_cellfixed(8,7,0);
   set_cellfixed(8,8,3);
   set_cellfixed(8,9,0);
   set_cellfixed(9,1,5);
   set_cellfixed(9,2,0);
   set_cellfixed(9,3,7);
   set_cellfixed(9,4,8);
   set_cellfixed(9,5,9);
   set_cellfixed(9,6,3);
   set_cellfixed(9,7,6);
   set_cellfixed(9,8,1);
   set_cellfixed(9,9,2);
   
}

void Grid::loadHard()
{
   clear();
   set_cellfixed(1, 1, 6);set_cellfixed(6, 6, 8);
   set_cellfixed(1, 9, 5);set_cellfixed(6, 8, 1);
   set_cellfixed(2, 2, 4);set_cellfixed(7, 3, 1);
   set_cellfixed(2, 6, 3);set_cellfixed(7, 6, 6);
   set_cellfixed(3, 1, 2);set_cellfixed(7, 7, 2);
   set_cellfixed(3, 2, 3);set_cellfixed(8, 3, 3);
   set_cellfixed(5, 4, 3);set_cellfixed(8, 9, 7);
   set_cellfixed(5, 5, 2);set_cellfixed(9, 1, 9);
   set_cellfixed(5, 7, 8);set_cellfixed(9, 4, 4);
   set_cellfixed(5, 8, 7);set_cellfixed(9, 5, 5);
   set_cellfixed(4, 1, 3);set_cellfixed(9, 7, 6);
   set_cellfixed(4, 4, 1);set_cellfixed(9, 9, 1);
   set_cellfixed(4, 7, 5);
   set_cellfixed(4, 8, 4);
}


bool Grid::solve()
{
  if(!errors && !solved)
  {
      solveUtil();
      return true;
  }
  else 
  {
   return false;  
  } 
   
}

void Grid::set_cell(int c1, int c2, int val)
{
  grid[c1-1][c2-1].set_val(val);
}
void Grid::set_cellfixed(int c1, int c2, int val)
{
  set_cell(c1, c2, val);
  if(val!=0)
   grid[c1-1][c2-1].set_fixed(1);
}
void Grid::set_selectedCell(Cell* c)
{
   selectedCell = c;
}

Cell* Grid::get_selectedCell()
{
   return selectedCell;
}
Cell* Grid::get_cell(int c1, int c2)
{
  return &grid[c1][c2];
}


void Grid::Init()
{
   for(int i=0; i<GRID_S; i++)
      for(int j=0; j<GRID_S; j++)
      {
         grid[i][j].rect_color(sf::Color::White);
         grid[i][j].text_color(sf::Color::Black);
      }       
   solved=false;
   errors=false;
}

void Grid::Draw(sf::RenderWindow &window, sf::Font font)
{
  CheckSolved();

  if(solved == true)
  {
   for(int i=0; i<GRID_S; i++)
      for(int j=0; j<GRID_S; j++)
         grid[i][j].text_color(sf::Color::Green);
  }
  else
  {
   for(int i=0; i<GRID_S; i++)
    for(int j=0; j<GRID_S; j++)
      grid[i][j].text_color(sf::Color::Black);
  }

  MarkConflicting();

  for (int i=0; i<GRID_S; i++)
  {
    for (int j=0; j<GRID_S; j++)
      if(grid[i][j].get_fixed()==true)
         grid[i][j].text_color(sf::Color::Blue);  
  }

  for(int i=0; i<GRID_S; i++)
  {
    int c2 = MARG + i*CELL_SIZE;
    for (int j=0; j<GRID_S; j++)
    {
      int c1 = MARG + j*CELL_SIZE + 1;
      grid[i][j].draw(window, font, c1, c2);
    }
  }


  {
   sf::RectangleShape line(sf::Vector2f(2, GRID_S * CELL_SIZE));
   line.setFillColor(sf::Color::Black);

   line.setPosition(MARG, MARG);
   window.draw(line);
   line.setPosition(MARG + CELL_SIZE*3, MARG);
   window.draw(line);
   line.setPosition(MARG + CELL_SIZE*6, MARG);
   window.draw(line);
   line.setPosition(MARG + CELL_SIZE*9, MARG);
   window.draw(line);
  }

  {
   sf::RectangleShape line(sf::Vector2f(GRID_S * CELL_SIZE, 2));
   line.setFillColor(sf::Color::Black);

   line.setPosition(MARG, MARG);
   window.draw(line);
   line.setPosition(MARG, MARG + CELL_SIZE*3);
   window.draw(line);
   line.setPosition(MARG, MARG + CELL_SIZE*6);
   window.draw(line);
   line.setPosition(MARG, MARG + CELL_SIZE*9);
   window.draw(line);
  }

}

void Grid::CellClicked(sf::RenderWindow &window, sf::Vector2f &mouse)
{
   for(int i=0; i<GRID_S; i++)
       for(int j=0; j<GRID_S; j++)
            grid[i][j].set_hidden(false);

   if(selectedCell)
      selectedCell->rect_color(sf::Color::White);

   selectedCell = NULL;

   for(int i=0; i<GRID_S; i++)
     for(int j=0; j<GRID_S; j++)
     {
      if(grid[i][j].selected(mouse) && !grid[i][j].get_fixed())
         {
            selectedCell = &grid[i][j];
            std::cout<<i<<' '<<j<<' '<<grid[i][j].get_val()<<'\n'; 
            std::cout<<selectedCell->get_val()<<'\n';
            grid[i][j].set_hidden(true);

            sf::Color color(203, 203, 203);
            selectedCell->rect_color(color);
         }
     }             
}  

void Grid::CellHovered(sf::RenderWindow &window, sf::Vector2f &mouse)
{
   sf::Color color(203, 203, 203);
   for(int i=0; i<GRID_S; i++)
     for(int j=0; j<GRID_S; j++)
     {
      if(!selectedCell)
      {
         if(grid[i][j].selected(mouse))
            grid[i][j].rect_color(color);
         else  
            grid[i][j].rect_color(sf::Color::White);
      }
   }             
} 

void Grid::CellEntered()
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
      selectedCell->set_hidden(false);
      selectedCell->rect_color(sf::Color::White);
      selectedCell = NULL; 

} 

