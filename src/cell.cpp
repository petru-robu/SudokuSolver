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
void Cell::display(sf::RenderWindow &window, sf::Font font, int px, int py)
{
  rect->setFillColor(sf::Color::White);
  rect->setOutlineThickness(1.f);

  text->setFont(font);
  std::string st=""; 
  if(val>=1 && val<=9)
    st+= toStr(val);
  text->setString(st);
  text->setCharacterSize(cell_size-10);

  rect->setPosition(px, py);
  text->setPosition(px+6,py+2);

  window.draw(*rect);

  if(!hidden)
    window.draw(*text);
}

int Cell::get_cell_size()
{
  return cell_size;
}

bool Cell::selected(sf::Vector2f &mouse)
{
  if(rect->getGlobalBounds().contains(mouse))
    return true;
  else return false;
}

bool Cell::get_view()
{
  return hidden;
}
void Cell::set_view(bool a)
{
  if(a==1)
    hidden = 0;
  else 
    hidden=1;
}

void Cell::set_color(sf::Color col)
{
  text->setFillColor(col);
  rect->setOutlineColor(col);
}