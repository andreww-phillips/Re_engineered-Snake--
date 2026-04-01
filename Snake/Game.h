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
    std::string game_state = "Starting"; 

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;         
    Uint32 startTime = SDL_GetTicks(); 

    Game();
    ~Game();

    void handleInput();
    void update();
    void draw();
    void run();
};