#ifndef MENU_H
#define MENU_H

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#define NRB 5

struct Button
{
    sf::Text text;
    std::string label;
};


class Menu
{

private:

    Button* buttons = new Button[NRB+1]; 
    sf::Font ff;


public:
    Menu(){}
    ~Menu();

    void Init(sf::Font font);
    void Draw(sf::RenderWindow &window);
    void Hovered(sf::RenderWindow &window, sf::Vector2f &mouse);
    int Clicked(sf::RenderWindow &window, sf::Vector2f &mouse);


};



#endif