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


        // Using a deque data structure we add a new head to the snake by adding the coordinates of the direction
        // to the position of the original head and then consecutively popping the tail of the snake.
        void move(){
            Vec2 newHead = {body.front().x + direction.x, body.front().y + direction.y};
            body.push_front(newHead);
            body.pop_back();
        }

        //Similarly to move, we add the new head to the snake but we do not pop the tail, this way the snake grows by one unit.
        void eat(){
            Vec2 newHead = {body.front().x + direction.x, body.front().y + direction.y};
            body.push_front(newHead);
        }

        // Implened the conditions for the snake to be dead 
        bool isDead(){
            // Check if the snake has collided with the walls on the x-axis
            if(body.font().x <=0 || body.front().x >= 20){
                return true;
            }

            // Check if the snake has collided with the walls on the y-axis
            if(body.front().y <=0 || body.front().y >= 20){
                return true;
            }

            // Check if the snake has collided with itself
            for(size_t i = 1; i < body.size(); ++i){
                if(body.front() == body[i]){
                    return true;
                }
            }

            return false;
        }

};