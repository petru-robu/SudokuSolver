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

  sf::RenderWindow window(sf::VideoMode(800, 600), "Sudoku Game!");  

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

}
