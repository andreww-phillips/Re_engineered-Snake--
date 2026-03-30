#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO); // renders key event and graphics
    Game game;
    game.run();
    SDL_Quit();
    return 0;
}