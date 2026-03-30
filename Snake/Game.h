#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include "Snake.h"
#include "Food.h"
#include "Constants.h"

class Game {
public:
    Snake snake;
    Food food;
    bool running = true;
    int score = 0;         
    Uint32 startTime = SDL_GetTicks();  

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    Game();
    ~Game();

    void handleInput();
    void update();
    void draw();
    void run();
};