#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO); // Renders inputs and graphics
    Game game;
    game.run();
    SDL_Quit();
    return 0;
}