#include "../include/menu.h"
Menu::~Menu()
{
    std::cout<<"Destructor apelat pentru Menu!\n";
    delete[] buttons;
}

void Menu::Init(sf::Font font)
{
    ff=font;
    buttons[1].label = "Solve";
    buttons[2].label = "Clear";
    buttons[3].label = "Load Easy";
    buttons[4].label = "Load Hard";
    buttons[5].label = "Credits";

    for(int i=1; i<=NRB; i++)
    {
        buttons[i].text.setFont(ff);
		buttons[i].text.setCharacterSize(32);

		buttons[i].text.setString(buttons[i].label);
		buttons[i].text.setPosition(310-buttons[i].text.getGlobalBounds().width/2, 576+i*37);

        buttons[i].text.setFillColor(sf::Color::Black);
    }
}

void Menu::Draw(sf::RenderWindow &window)
{
    for(int i=1; i<=NRB; i++)
		window.draw(buttons[i].text);
}

void Menu::Hovered(sf::RenderWindow &window, sf::Vector2f &mouse)
{
    sf::Color color(162, 162, 162);
    for(int i=1; i<=NRB; i++)
        if (buttons[i].text.getGlobalBounds().contains(mouse))
			buttons[i].text.setFillColor(color);
		else 
            buttons[i].text.setFillColor(sf::Color::Black);
}

int Menu::Clicked(sf::RenderWindow &window, sf::Vector2f &mouse)
{
    for(int i=1; i<=NRB; i++)
      if(buttons[i].text.getGlobalBounds().contains(mouse))
		return i;
    return 0;
}
