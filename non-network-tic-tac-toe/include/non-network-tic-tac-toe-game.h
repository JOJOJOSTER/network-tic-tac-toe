#pragma once

#include "map.h"
#include <array>
#include <iostream>
#include <sstream>

class GameTicTacToe {

public:
  class Player {
  public:
    Player(int number, char symbol) : m_number(number), m_symbol(symbol) {}
    Player(const Player &other) = default;

    void setNumber(int number) { m_number = number; }
    void setSymbol(char symbol) { m_symbol = symbol; }

    int getNumber() const { return m_number; }
    char getSymbol() const { return m_symbol; }

  private:
    int m_number;
    char m_symbol;
  };

public:
  GameTicTacToe() : map(3, 3) {}

  bool isCoordinateInRange(int x, int y) const {

    return (x >= 0 && x < map.getWeight() && y >= 0 && y < map.getHeight());
  }

  bool inputCoordinateForStep(int &x, int &y);

  void inputCoordinateUntilGetCorrect(int &x, int &y);

  const Player &getCurrentPlayerWhoDoMoveBetweenTwoPlayers(
      const std::array<Player, 2> &players, int moves) {
    return players[moves % 2];
  }

  const Player &getPlayerWhoDoNotMoveNovBeetweenTwoPlayers(
      const std::array<Player, 2> &players, int moves);

  void playerMove(const Player &player);

  bool isWinOnThreeGridMap(const Player &player);

  void game();

private:
  Map map;
};
