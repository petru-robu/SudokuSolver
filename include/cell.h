#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>


class Cell
{
private:

  static const int cell_size = 30;
  int val;
  char toStr(int x);
  bool hidden;

  sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(cell_size, cell_size));
  sf::Text *text = new sf::Text;
  

public:

  Cell() : val(0) {hidden=0;}
  Cell(int x) : val(x) {hidden=0;}

  void display(sf::RenderWindow &window, sf::Font font, int px, int py);

  void set_val(int x);
  void set_color(sf::Color col);
  void set_view(bool a);

  int get_val();
  int get_cell_size();
  bool get_view();

  bool selected(sf::Vector2f &mouse);

};

#endif
