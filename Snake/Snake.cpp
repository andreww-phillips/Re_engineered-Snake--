#include <iostream>
#include <deque>

class Snake{
    struct Vec2 { //Creates a struct for the snake/body and its direction
        int x, y;
        bool operator==(const Vec2& other) const {
            return x == other.x && y == other.y;
        }
    };

    public:
        std::deque<Vec2> body = {{0, 0}}; //Controls the snake's body and it's inital position at the top left corner
        Vec2 direction={1,0}; //INITIAL DIRECTION: Right


        void move(){
            
        }

        void eat(){

        }

        bool isDead(){
            
        }

};