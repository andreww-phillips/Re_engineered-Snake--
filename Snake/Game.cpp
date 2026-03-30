#include "Game.h"
#include <SDL.h>
#include <ctime>

    Game::Game() {
        // Reseed the random number generator for spawning food in different positions
        srand(time(0));
        // Creates the OS window 
        window = SDL_CreateWindow("Snake",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            600, 600, 0);
        // Creates the renderer. -1 picks the first available graphics driver and 0 means no special flags    
        renderer = SDL_CreateRenderer(window, -1, 0);
        // Spawns the initial food 
        food.spawn(snake.body);
    }

    Game::~Game() {
        // Clean up SDL resources when the game is destroyed
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
        // Handles if the snake initially spawns on the food
        if (snake.body.front() == food.position) {
            snake.eat();
            food.spawn(snake.body);
        } else {
            snake.move();
        }
        // Handles the game over event when the snake dies. Returns a message box allowing the user to quit or play again
        if (snake.isDead()) {
            SDL_MessageBoxButtonData buttons[] = {
                // flags, buttonid, text
                { 0, 0, "Quit" },   
                { 0, 1, "Play Again" }
            };
            // Packs everything up into one struct. Includes the error message and the "Quit" and "Play Again" buttons
            SDL_MessageBoxData messageboxdata = {
                SDL_MESSAGEBOX_ERROR,   
                window,                 
                "Game Over",            
                "You died!",            
                2,                      
                buttons,                
                nullptr                
            };
            
            // Function call to implement the display of the struct defined just above with the error message and user end of game handling
            int buttonid;
            SDL_ShowMessageBox(&messageboxdata, &buttonid);

            //Response the snake if user decides to play again, otherwise quit the game
            if (buttonid == 1) {
                // reset the game
                snake.body = {{0, 0}};
                snake.direction = {1, 0};
                food.spawn(snake.body);
            } else {
                running = false;
            }
        }
    }

    void Game::draw() {
        // Black play area
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Choose the colour: black
        SDL_Rect playArea = { 0, 0, GRID_WIDTH * CELL_SIZE, GRID_HEIGHT * CELL_SIZE }; // Defines the boundaries of the play area
        SDL_RenderFillRect(renderer, &playArea); // Fills the earlier defined play area with the chosen colour

        // Optional: subtle grid lines
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255); // Choose the colour: grey
        for (int x = 0; x <= GRID_WIDTH; ++x) { // Draw vertical grid lines
            SDL_RenderDrawLine(renderer, x * CELL_SIZE, 0, x * CELL_SIZE, GRID_HEIGHT * CELL_SIZE);
        }    
        for (int y = 0; y <= GRID_HEIGHT; ++y){ // Draw horizontal grid lines
            SDL_RenderDrawLine(renderer, 0, y * CELL_SIZE, GRID_WIDTH * CELL_SIZE, y * CELL_SIZE);
        }    

        // To determine the direction of the snake better, I defined the head of the snake to be a brighter green and
        // the body to be a darker green
        for (size_t i = 0; i < snake.body.size(); ++i) {
            const Vec2& segment = snake.body[i]; // Get the coordinates of the current snake segment
            SDL_Rect rect = { segment.x * CELL_SIZE, segment.y * CELL_SIZE, CELL_SIZE, CELL_SIZE }; // Define the rectangle for the current snake segment. Parameters are x, y, width, height

            if (i == 0)
                SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255); // bright green head
            else
                SDL_SetRenderDrawColor(renderer, 0, 180, 0, 255);     // darker green body

            SDL_RenderFillRect(renderer, &rect); // Draw the snake segment
        }

        // Draw the food
        SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
        SDL_Rect foodRect = {
            food.position.x * CELL_SIZE,
            food.position.y * CELL_SIZE,
            CELL_SIZE,
            CELL_SIZE
        };
        SDL_RenderFillRect(renderer, &foodRect);

        SDL_RenderPresent(renderer);
    }

    // Main game loop that iterates in a loop until the user decides to quit or the snake dies
    void Game::run() {
        running = true;
        while (running) {
            handleInput();
            update();
            draw();
            SDL_Delay(100); 
        }
    }