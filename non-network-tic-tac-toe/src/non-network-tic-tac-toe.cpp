#include "../include/non-network-tic-tac-toe-game.h"
#include <iostream>

int main() {

  std::cout << "Hello world!" << std::endl;

  GameTicTacToe game;

  if (!game.game()) {
    std::cout << "No one win" << std::endl;
  }

  /*
    Map map;
    map.clearMap('X');
    map.setSymbolToMap(1, 1, 'O');

    printSquareMap(map);
    std::cout << std::endl;
    printSquareMapWithSeparators(map);

  */

  return 0;
}
