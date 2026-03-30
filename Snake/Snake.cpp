#include <deque>
#include "Snake.h"
#include "Constants.h"

// Using a deque data structure we add a new head to the snake by adding the coordinates of the direction
// to the position of the original head and then consecutively popping the tail of the snake.
void Snake::move(){
    Vec2 newHead = {body.front().x + direction.x, body.front().y + direction.y};
    body.push_front(newHead);
    body.pop_back();
}

//Similarly to move, we add the new head to the snake but we do not pop the tail, this way the snake grows by one unit.
void Snake::eat(){
    Vec2 newHead = {body.front().x + direction.x, body.front().y + direction.y};
    body.push_front(newHead);
}

// Implened the conditions for the snake to be dead 
bool Snake::isDead(){
    // Check if the snake has collided with the walls on the x-axis
    if(body.front().x <0 || body.front().x >= 20){
        return true;
    }

    // Check if the snake has collided with the walls on the y-axis
    if(body.front().y <0 || body.front().y >= 20){
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
