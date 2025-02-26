#include "../include/non-network-tic-tac-toe-game.h"

bool GameTicTacToe::inputCoordinateForStep(int &x, int &y) {
  std::string coordinate;
  std::getline(std::cin, coordinate);

  std::istringstream parser(coordinate);

  int parsedX = 0;
  int parsedY = 0;

  if (parser >> parsedX >> parsedY) {
    x = parsedX;
    y = parsedY;
    return true;
  }

  return false;
}

void GameTicTacToe::inputCoordinateUntilGetCorrect(int &x, int &y) {

  do {

    std::cout << "Write coordinate (x y): ";

    if (inputCoordinateForStep(x, y)) {
      return;
    }

    std::cout << "\nNot correct, try again." << std::endl;

  } while (true);
}

const GameTicTacToe::Player &
GameTicTacToe::getPlayerWhoDoNotMoveNovBeetweenTwoPlayers(
    const std::array<Player, 2> &players, int moves) {
  int currentPlayer = moves % 2;

  if (moves == 0) {
    return players[currentPlayer + 1];
  } else {
    return players[currentPlayer - 1];
  }
}

void GameTicTacToe::playerMove(const Player &player) {
  int x;
  int y;

  while (true) {
    inputCoordinateUntilGetCorrect(x, y);

    if (!isCoordinateInRange(x, y)) {
      std::cout << "Coordinate is range out." << std::endl;
      continue;
    }

    if (map.getSymbolFromMap(x, y) != ' ') {
      std::cout << "Coordinate are eccupied." << std::endl;
      continue;
    }

    break;
  }

  map.setSymbolToMap(x, y, player.getSymbol());
}

bool GameTicTacToe::isWinOnThreeGridMap(const Player &player) {
  // Brunch 3 x 3 map

  for (int iii = 0; iii < 3; ++iii) {
    if (map.getSymbolFromMap(iii, 0) == map.getSymbolFromMap(iii, 1) &&
        map.getSymbolFromMap(iii, 1) == map.getSymbolFromMap(iii, 2) &&
        map.getSymbolFromMap(iii, 0) == player.getSymbol()) {
      return true;
    }
  }

  for (int iii = 0; iii < 3; ++iii) {
    if (map.getSymbolFromMap(0, iii) == map.getSymbolFromMap(1, iii) &&
        map.getSymbolFromMap(1, iii) == map.getSymbolFromMap(2, iii) &&
        map.getSymbolFromMap(0, iii) == player.getSymbol()) {
      return true;
    }
  }

  if (map.getSymbolFromMap(0, 0) == map.getSymbolFromMap(1, 1) &&
      map.getSymbolFromMap(1, 1) == map.getSymbolFromMap(2, 2) &&
      map.getSymbolFromMap(0, 0) == player.getSymbol()) {
    return true;
  }

  if (map.getSymbolFromMap(2, 0) == map.getSymbolFromMap(1, 1) &&
      map.getSymbolFromMap(1, 1) == map.getSymbolFromMap(0, 2) &&
      map.getSymbolFromMap(2, 0) == player.getSymbol()) {
    return true;
  }

  return false;
}

void GameTicTacToe::game() {

  std::cout << "Welcome to game" << std::endl << std::endl;

  std::array<Player, 2> players({Player(1, 'X'), Player(2, 'O')});

  int movesCounter = 0;

  //
  int maxMovesInGame = map.getWeight() * map.getHeight() - 1;

  Map::PrintMap::clearConsole();
  Map::PrintMap::printSquareMapWithSeparators(map);

  while (movesCounter <= maxMovesInGame) {

    // symbol cyrrent player
    Player currentPlayer =
        getCurrentPlayerWhoDoMoveBetweenTwoPlayers(players, movesCounter);

    std::cout << std::endl;

    std::cout << currentPlayer.getNumber() << " player step: " << std::endl;

    playerMove(currentPlayer);

    ++movesCounter;

    Map::PrintMap::clearConsole();
    Map::PrintMap::printSquareMapWithSeparators(map);

    if (isWinOnThreeGridMap(currentPlayer)) {
      std::cout << "Player " << currentPlayer.getNumber() << " ("
                << currentPlayer.getSymbol() << ") is winner!" << std::endl;
      break;
    }
  }

  std::cout << "No one win" << std::endl;
}
