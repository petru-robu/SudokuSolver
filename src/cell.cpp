#include "../include/cell.h"

char Cell::toStr(int x)
{
  return (char)(x+48);
}
void Cell::set_val(int x)
{
  val = x;
}
int Cell::get_val()
{
  return val;
}
void Cell::display(sf::RenderWindow &window, sf::Font font, int px, int py, int size)
{
  sf::RectangleShape rect(sf::Vector2f(size, size));
  rect.setFillColor(sf::Color::White);
  rect.setOutlineThickness(1.f);
  rect.setOutlineColor(sf::Color::Black);

  sf::Text text;
  text.setFont(font);
  std::string st=""; st+= toStr(val);
  text.setString(st);
  text.setFillColor(sf::Color::Black);
  text.setCharacterSize(size-10);

  rect.setPosition(px, py);
  text.setPosition(px+6,py+2);
  window.draw(rect);
  window.draw(text);
}
