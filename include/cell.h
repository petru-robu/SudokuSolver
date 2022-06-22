#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


class Cell
{
private:

  int val;
  char toStr(int x);

public:

  Cell() : val(0) {}
  Cell(int x) : val(x) {}
  void display(sf::RenderWindow &window, sf::Font font, int px, int py, int size);
  void set_val(int x);
  int get_val();

};

#endif
