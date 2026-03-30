#include <iostream>
#include <deque>

class Food{
    struct Vec2 { //Creates a struct for the snake/body and its direction
        int x, y;
        bool operator==(const Vec2& other) const {
            return x == other.x && y == other.y;
        }
    };

    public:
        Vec2 position;

        void spawn(){

        }
};