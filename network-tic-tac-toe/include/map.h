#pragma once

#include <cassert>
#include <iostream>
#include <vector>

class Map {
  using MapSquare = std::vector<std::vector<char>>;

public:
  Map(int weight = 3, int height = 3);

  // @param weight of map
  // @param height of map
  //
  bool resizeMap(int weight, int height);

  void setSymbolToMap(int x, int y, char symbol);

  char getSymbolFromMap(int x, int y) const;

  void clearMap(char symbol = ' ');
  // MapSquare &getMap() { return map; }
  const MapSquare &getMap() const { return map; }

  int getWeight() const { return map.size(); }
  int getHeight() const { return map[0].size(); }

  class PrintMap {
  public:
    static void printSquareMap(const Map &map);

    /*
    1|2|3
    -*-*-
    4|5|6
    -*-*-
    7|8|9
    */

    static void printSquareMapWithSeparators(const Map &map);

    // Print ASNI code for clear console
    // "\033[2J"
    static void clearConsole() { std::cout << "\033[2J"; }
  };

private:
  MapSquare map;
};
