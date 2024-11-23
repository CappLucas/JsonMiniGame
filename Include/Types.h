#pragma once

#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct Cooridinate {
  Cooridinate(float nX, float nY) : x(nX), y(nY) {}

  float x, y;

  Cooridinate operator+(Cooridinate &coord) {
    return {coord.x + x, coord.y + y};
  }
  Cooridinate operator-(Cooridinate &coord) {
    return {coord.x - x, coord.y - y};
  }
  Cooridinate operator*(Cooridinate &coord) {
    return {coord.x * x, coord.y * y};
  }
  Cooridinate operator/(Cooridinate &coord) {
    return {coord.x / x, coord.y / y};
  }
};