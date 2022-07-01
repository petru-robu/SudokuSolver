#include "../include/cell.h"

Cell::Cell() : val(0)
{
  rect = new sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
  hidden = false;
  fixed=false;
}

Cell::~Cell()
{
  delete rect;
  delete text;
  std::cout<<"Destructor apelat pentru Cell!\n";
}

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

void Cell::draw(sf::RenderWindow &window, sf::Font font, int px, int py)
{
  rect->setOutlineThickness(1.f);
  rect->setOutlineColor(sf::Color::Black);

  text->setFont(font);
  std::string st=""; 
  if(val>=1 && val<=9)
    st+= toStr(val);

  text->setString(st);
  text->setCharacterSize(CELL_SIZE-10);

  rect->setPosition(px, py);
  text->setPosition(px+12,py+4);

  window.draw(*rect);

  if(!hidden)
    window.draw(*text);
}

bool Cell::selected(sf::Vector2f &mouse)
{
  if(rect->getGlobalBounds().contains(mouse))
    return true;
  else return false;
}

bool Cell::get_hidden()
{
  return hidden;
}

void Cell::set_hidden(bool a)
{
  hidden=a;
}

bool Cell::get_fixed()
{
  return fixed;
}

void Cell::set_fixed(bool a)
{
  fixed=a;
}

void Cell::text_color(sf::Color textCol)
{
  text->setFillColor(textCol);
  
}

void Cell::rect_color(sf::Color rectCol)
{
  rect->setFillColor(rectCol);
}