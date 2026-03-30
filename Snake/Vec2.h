#pragma once

// Creates a template for the coordinate structure for the snake/snake body and the food position
struct Vec2{
    int x, y;
    bool operator==(const Vec2& other){
        return x == other.x && y == other.y;
    }
};