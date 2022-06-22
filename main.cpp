#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

#include "include/grid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(310, 410), "Sudoku Game");

    sf::Font font;
    if(!font.loadFromFile("resources/Hack-Regular.ttf"))
      {std::cout<<"Nu s-a incarcat fontul!"; return -1;}

    Grid sudoku;

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2f mouse(sf::Mouse::getPosition(window));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        sudoku.display(window, font, 20, 30);
        sudoku.solve();

        window.display();
    }
    return 0;
}
