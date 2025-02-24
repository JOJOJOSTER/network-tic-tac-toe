#include "../include/map.h"

Map::Map(int weight, int height) {
  resizeMap(weight, height);
  clearMap();
}

bool Map::resizeMap(int weight, int height) {

  map.resize(weight);

  for (auto &colomn : map) {
    colomn.resize(height);
  }

  return true;
}

void Map::setSymbolToMap(int x, int y, char symbol) {
  assert(x >= 0 && x <= getWeight() && y >= 0 && y <= getHeight() &&
         "Error - setSymbolToMap(): range out");

  map[x][y] = symbol;
}

char Map::getSymbolFromMap(int x, int y) const {

  assert(x >= 0 && x <= getWeight() && y >= 0 && y <= getHeight() &&
         "Error - setSymbolToMap(): range out");

  return map[x][y];
}

void Map::clearMap(char symbol) {
  for (int x = 0; x < getWeight(); ++x) {
    for (int y = 0; y < getHeight(); ++y) {
      setSymbolToMap(x, y, symbol);
    }
  }
}

void Map::PrintMap::printSquareMap(const Map &map) {
  for (int y = 0; y < map.getHeight(); ++y) {
    for (int x = 0; x < map.getWeight(); ++x) {
      std::cout << map.getSymbolFromMap(x, y);
    }
    std::cout << std::endl;
  }
}

void Map::PrintMap::printSquareMapWithSeparators(const Map &map) {

  for (int y = 0; y < map.getHeight(); ++y) {
    for (int x = 0; x < map.getWeight(); ++x) {

      std::cout << map.getSymbolFromMap(x, y);

      // Print '|' separator
      // X|O|X
      //
      if ((x + 1) != map.getWeight()) {
        std::cout << '|';
      }
    }

    std::cout << std::endl;

    if ((y + 1) != map.getHeight()) {
      // Print '-+' of '-' separators
      // -+-+-
      //
      for (int iii = 0; iii < map.getHeight(); ++iii) {

        if ((iii + 1) != map.getWeight()) {
          std::cout << "-+";
        } else {
          // In end we don't need +
          // -+-
          std::cout << '-';
        }
      }
    }

    std::cout << std::endl;
  }
}
