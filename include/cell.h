#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

#define CELL_SIZE 60


class Cell
{
private:

  int val;
  bool hidden;
  bool fixed;

  char toStr(int x);

  sf::RectangleShape *rect;
  sf::Text *text = new sf::Text;
  

public:

  Cell();
  ~Cell();

  void draw(sf::RenderWindow &window, sf::Font font, int px, int py);

  void set_val(int x);
  int get_val();

  void set_hidden(bool a);
  bool get_hidden();

  void set_fixed(bool a);
  bool get_fixed();

  void text_color(sf::Color textCol);
  void rect_color(sf::Color rectCol);
  
  bool selected(sf::Vector2f &mouse);

};

#endif
