#pragma once

struct Vec2{
    int x, y;
    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }
};