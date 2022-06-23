#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

#include "include/grid.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(310, 410), "Sudoku Game");

    sf::Font font;
    if(!font.loadFromFile("resources/Hack-Regular.ttf"))
      {std::cout<<"Nu s-a incarcat fontul!"; return -1;}


    sf::Text tex[4];

	std::string str[] = {"Solve","Credits","Clear","Exit"};
	for (int i = 0; i<4; i++)
	{
		tex[i].setFont(font);
		tex[i].setCharacterSize(20);

		tex[i].setString(str[i]);
		tex[i].setPosition(155-tex[i].getGlobalBounds().width/2, 310 + i*20);
	}

    Grid sudoku;
    sudoku.solve();
    sudoku.prepareDisplay();

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2f mouse(sf::Mouse::getPosition(window));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            sudoku.manageCellsOnHover(window, mouse);

            if(event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                sudoku.manageCellsOnClick(window, mouse);
                if(tex[0].getGlobalBounds().contains(mouse))
                {
                    sudoku.solve();
                }
                if(tex[2].getGlobalBounds().contains(mouse))
                {
                    sudoku.clear();
                }
                if(tex[3].getGlobalBounds().contains(mouse))
                {
                    window.close();
                }
            }
            if(event.type==sf::Event::KeyPressed)
            {
                sudoku.manageCellsOnInput(window, mouse);
            }

        }

        window.clear(sf::Color::White);

        sudoku.display(window, font, 20);

        for (int i = 0; i<4; i++)
			if (tex[i].getGlobalBounds().contains(mouse))
				tex[i].setColor(sf::Color::Red);
			else 
                tex[i].setColor(sf::Color::Black);

    
        for (int i=0; i<4; i++)
				window.draw(tex[i]);

        window.display();
    }
    return 0;
}
