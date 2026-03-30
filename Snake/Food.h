#pragma once
#include <deque>
#include "Vec2.h"

class Food {
public:
    Vec2 position;

    void spawn(const std::deque<Vec2>& body);
    bool isOnSnake(const std::deque<Vec2>& body);
};