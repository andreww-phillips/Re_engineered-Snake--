#include <deque>
#include <cstdlib>
#include "Food.h"
#include "Constants.h"

// Generate food at random positions within the grid, making sure they're not in positions occupied
// by the snake's body
void Food::spawn(const std::deque<Vec2>& body){
    do{
        position.x = rand() % GRID_WIDTH;
        position.y = rand() % GRID_HEIGHT;
    }while(isOnSnake(body));
}

// Instance checking for food spawning to ensure that the food does not spawn on the snake's body
bool Food::isOnSnake(const std::deque<Vec2>& body){
    for(const Vec2& segment : body){
        if(position == segment){
            return true;
        }
    }
    return false;
}
