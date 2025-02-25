#include "../include/network-tic-tac-toe-game.h"
#include <iostream>

int main() {

  std::cout << "Hello world!" << std::endl;

  GameTicTacToe game;

  if (!game.game()) {
    std::cout << "No one win" << std::endl;
  }

  return 0;
}
