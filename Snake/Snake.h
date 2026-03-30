#pragma once
#include <deque>
#include "Vec2.h"

class Snake {
public:
    std::deque<Vec2> body = {{0, 0}};
    Vec2 direction = {1, 0};

    void move();
    void eat();
    bool isDead();
};