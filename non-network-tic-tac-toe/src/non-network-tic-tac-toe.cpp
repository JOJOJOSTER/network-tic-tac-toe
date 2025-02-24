#include "../include/non-network-tic-tac-toe-game.h"
#include <iostream>

/*

    1|2|3
    -*-*-
    4|5|6
    -*-*-
    7|8|9

*/

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
