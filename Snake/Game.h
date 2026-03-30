#pragma once

#include <SDL.h>
#include "Snake.h"
#include "Food.h"

class Game {
public:
    Snake snake;
    Food food;
    bool running = true;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    Game();
    ~Game();

    void handleInput();
    void update();
    void draw();
    void run();
};