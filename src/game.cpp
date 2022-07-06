#include "../include/game.h"

Game* Game::instance = 0;

Game::Game()
{}
Game::~Game()
{
    delete window;
    std::cout<<"Destructor apelat pentru Game!\n";
}
Game* Game::get_instance()
{
    if(!instance)
    
        instance = new Game;
    return instance;
}

void Game::init(int window_sizeX, int window_sizeY)
{
    window = new sf::RenderWindow(sf::VideoMode(window_sizeX, window_sizeY), "Sudoku Game!");

    if(!font.loadFromFile("resources/Hack-Regular.ttf"))
      {std::cout<<"Nu s-a incarcat fontul!"; return;}
      
    sudoku.Init();
    menu.Init(font);
}
void Game::runGame()
{
    init(620, 820);
    while(window->isOpen())
    {
        sf::Event event;
        mouse = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));

        while(window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                manageLeftClick();
            }
            if(event.type==sf::Event::KeyPressed)
            {
                manageKeyPress();
            }
        }
        manageHovers();
        updateFrame();
    }
}


void Game::updateFrame()
{
    window->clear(sf::Color::White);

    sudoku.Draw(*window, font);
    menu.Draw(*window);
    
    window->display();
}


void Game::manageLeftClick()
{
   sudoku.CellClicked(*window, mouse);
    
   int x = menu.Clicked(*window, mouse);

   if(x==1)
    sudoku.solve();
   if(x==2)
    sudoku.clear();
   if(x==3)
    sudoku.loadEasy();
   if(x==4)
    sudoku.loadHard();
   if(x==5)
    Credits();
}
void Game::manageKeyPress()
{
    if(sudoku.get_selectedCell())
        sudoku.CellEntered();
}
void Game::manageHovers()
{
    sudoku.CellHovered(*window, mouse);
    menu.Hovered(*window, mouse);
}

void Game::Credits()
{
    sf::RenderWindow creditsWindow(sf::VideoMode(500, 395), "Credits!");

    sf::Font font1, font2;
    if(!font1.loadFromFile("resources/Hack-BoldItalic.ttf")||!font2.loadFromFile("resources/Hack-Italic.ttf"))
    {std::cout<<"Nu s-a incarcat fontul!"; return;}

    sf::Text nume ("Petru", font1);
    sf::Text madeby ("Sudoku-Solver facut de: ", font2);
    
    nume.setCharacterSize(23); nume.setFillColor(sf::Color::Black);
    madeby.setCharacterSize(20); madeby.setFillColor(sf::Color::Black);

    madeby.setPosition(30, 60);
    nume.setPosition(30+madeby.getGlobalBounds().width+3, 59);
    while(creditsWindow.isOpen())
    {
        sf::Event event;
        while(creditsWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
               creditsWindow.close();
        }
        creditsWindow.clear(sf::Color::White);
        creditsWindow.draw(nume);
        creditsWindow.draw(madeby);
        creditsWindow.display();
    }
}