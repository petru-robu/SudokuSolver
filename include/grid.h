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

  bool isPresentInCol(int col, int num);
  bool isPresentInRow(int row, int num);
  bool isPresentInBox(int brow, int bcol, int num);
  bool findEmptyPlace(int &row, int &col);
  bool isValidPlace(int row, int col, int num);
  bool solveUtil();

public:

  Grid();
  ~Grid();
  bool solve();
  void set_state(bool a);
  bool get_state();
  void set_cell(int c1, int c2, int val);
  int get_cell(int c1, int c2);

  void display(sf::RenderWindow &window, sf::Font font, int marg, int cell_size);

};


#endif
