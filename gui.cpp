#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "include/sudoku.h"
using namespace std;

ifstream fin("resources/sudoku.in");

int main()
{
  const int n = 9;
  int **v = new int*[n];
  for(int i=0; i<n; i++)
    v[i] = new int[n];

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      fin>>v[i][j];   

  Sudoku sud(n, v);

  sud.solve();

  sf::RenderWindow window(sf::VideoMode(413, 520), "Sudoku Game!");  

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        sf::RectangleShape tile(sf::Vector2f(35.f, 35.f));
        sf::RectangleShape line(sf::Vector2f(1.f, 371.f));

        tile.setFillColor(sf::Color(119,85,125));
        line.setFillColor(sf::Color(217,220,231));

        tile.move(20.f, 20.f);
        line.move(20.f, 20.f);

        for(int i=0; i<n; i++)
        {
          int offset;
          for(int j=0; j<n; j++)
          {
            offset = 42;
            window.draw(tile);
            if(i==0)
            {
              if(j!=0 && j%3==0)
              {
                line.move(-4.f, 0.f);
                window.draw(line);
                line.move(4.f, 0.f);
              }
                
              line.move(offset*1.f, 0.f);
            }

            tile.move(offset*1.f, 0.f);
          }
          if(i==0)
          {
            line.setRotation(90.f);
            line.move(-7.f, 0.f);
          }
          
          if(i!=0 && i%3==0)
            {
                line.move(0.f, -4.f);
                window.draw(line);
                line.move(0.f, 4.f);
            }
                
            line.move(0.f, offset*1.f);
            tile.move(((-1)*n*offset)*1.f, offset*1.f);
        }
          

        window.display();
    }

}
