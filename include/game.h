#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#include "cell.h"
#include "grid.h"
#include "menu.h"

class Game
{
private:
    Game();
    static Game* instance;

    sf::RenderWindow *window;
    sf::Font font;
    sf::Vector2f mouse;

    Grid sudoku;
    Menu menu;
    
    void init(int window_sizeX, int window_sizeY);
    void updateFrame();

    void manageLeftClick();
    void manageKeyPress();
    void manageHovers();

    void Credits();
    

public:
    ~Game();

    static Game* get_instance();
    void runGame();
};

#endif