#ifndef GRID_H
#define GRID_H

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "cell.h"

#define GRID_S 9

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

public:

  Grid();
  ~Grid();

  void prepareDisplay();
  void display(sf::RenderWindow &window, sf::Font font, int marg);

  bool solve();
  void clear();

  void set_state(bool a);
  void set_cell(int c1, int c2, int val);

  bool get_state();
  Cell& get_cell(int c1, int c2);

  void manageCellsOnClick(sf::RenderWindow &window, sf::Vector2f &mouse);
  void manageCellsOnHover(sf::RenderWindow &window, sf::Vector2f &mouse);
  void manageCellsOnInput(sf::RenderWindow &window, sf::Vector2f &mouse);

};


#endif
