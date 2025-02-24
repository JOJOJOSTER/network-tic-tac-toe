#pragma once

#include "map.h"
#include <array>
#include <iostream>
#include <sstream>

class GameTicTacToe {
public:
  GameTicTacToe() : map(3, 3) {}

  bool isCoordinateInRange(int x, int y) const {

    return (x >= 0 && x < map.getWeight() && y >= 0 && y < map.getHeight());
  }

  bool inputCoordinateForStep(int &x, int &y);

  void inputCoordinateUntilGetCorrect(int &x, int &y);

  struct Player {
    char symbol;
  };

  const Player &getCurrentPlayerWhoDoMove(const std::array<Player, 2> &players,
                                          int moves) {
    return players[moves % 2];
  }

  const Player &
  getOtherPlayerWhoWillMoveInNextRound(const std::array<Player, 2> &players,
                                       int moves);

  void playerMove(const Player &player);

  bool isWinOnThreeGridMap(const Player &player);

  bool game();

private:
  Map map;
};
