#ifndef GRID_H
#define GRID_H

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "cell.h"

#define GRID_S 9
#define MARG 40

class Grid
{
private:

  bool solved;
  Cell** grid;
  Cell* selectedCell;

  bool isPresentInCol(int col, int num);
  bool isPresentInRow(int row, int num);
  bool isPresentInBox(int brow, int bcol, int num);
  bool findEmptyPlace(int &row, int &col);
  bool isValidPlace(int row, int col, int num);
  bool solveUtil();
  void MarkConflicting();

  void set_cellfixed(int c1, int c2, int val);

public:

  Grid();
  ~Grid();

  bool solve();
  void clear();

  void Init();
  void Draw(sf::RenderWindow &window, sf::Font font);
  void CellClicked(sf::RenderWindow &window, sf::Vector2f &mouse);
  void CellHovered(sf::RenderWindow &window, sf::Vector2f &mouse);
  void CellEntered();

  void set_cell(int c1, int c2, int val);
  void set_selectedCell(Cell* c);

  Cell* get_cell(int c1, int c2);
  Cell* get_selectedCell();

  void loadEasy();
  void loadHard();

};


#endif
