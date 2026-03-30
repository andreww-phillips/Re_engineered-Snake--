#include <iostream>
#include <deque>
#include <cstdlib>

class Food{
    struct Vec2 { //Creates a struct for the snake/body and its direction
        int x, y;
        bool operator==(const Vec2& other) const {
            return x == other.x && y == other.y;
        }
    };

    public:
        Vec2 position;

        // Generate food at random positions within the grid, making sure they're not in positions occupied
        // by the snake's body
        void Food::spawn(const std::deque<Vec2>& body){
            do{
                position.x = rand() % 20;
                position.y = rand() % 20;
            }while(isOnSnake(body));
        }

        // Instance checking for food spawning to ensure that the food does not spawn on the snake's body
        bool isOnSnake(const std::deque<Vec2>& body){
            for(const Vec2& segment : body){
                if(position == segment){
                    return true;
                }
            }
            return false;
        }
};