#include "Vector2.hpp"
#include <cmath>

Vector2::Vector2() {
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2::~Vector2() {}

float Vector2::getMaginitude() { return std::sqrt((x * x) + (y * y)); }
