#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "include/game.h"

int main()
{
  Game* game;
  game = game->get_instance();

  game->runGame();
  return 0;
}