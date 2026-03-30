#include "Game.h"
#include <SDL.h>
#include <ctime>

    Game::Game() {
        srand(time(0));
        window = SDL_CreateWindow("Snake",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            600, 600, 0);
        renderer = SDL_CreateRenderer(window, -1, 0);
        food.spawn(snake.body);
    }

    Game::~Game() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }

    // Handle user input for controlling the snake's direction and quitting the game
    void Game::handleInput() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) { //Checks for events in the event queue, inputs event address from memory
            // Controls the quit event
            if (event.type == SDL_QUIT) {
                running = false;
            }
            // Controls key combinds using arrow keys and prevent the snake from going 180 degrees
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:    if (snake.direction.y != 1)  snake.direction = {0, -1}; break;
                    case SDLK_DOWN:  if (snake.direction.y != -1) snake.direction = {0,  1}; break;
                    case SDLK_LEFT:  if (snake.direction.x != 1)  snake.direction = {-1, 0}; break;
                    case SDLK_RIGHT: if (snake.direction.x != -1) snake.direction = {1,  0}; break;
                    case SDLK_ESCAPE: running = false; break;
                }
            }
        }
    }

    void Game::update() {
        if (snake.body.front() == food.position) {
            snake.eat();
            food.spawn(snake.body);
        } else {
            snake.move();
        }
        if (snake.isDead()) running = false;
    }

    void Game::draw() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw the snake
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for (const auto& segment : snake.body) {
            SDL_Rect rect = { segment.x * 20, segment.y * 20, 20, 20 };
            SDL_RenderFillRect(renderer, &rect);
        }

        // Draw the food
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect foodRect = { food.position.x * 20, food.position.y * 20, 20, 20 };
        SDL_RenderFillRect(renderer, &foodRect);

        SDL_RenderPresent(renderer);
    }

    void Game::run() {
        running = true;
        while (running) {
            handleInput();
            update();
            draw();
            SDL_Delay(100); 
        }
    }