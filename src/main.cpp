#include<SDL2/SDL.h>
#include"Game.h"
int main(int argc, char**argv){
	SDL_Log("Hello my Treasure\n");
	SDL_Init(SDL_INIT_EVERYTHING);
	Game game("Treasure", 600,600);
	game.run();
	SDL_Quit();
	SDL_Log("Terminated!");
	return 0;
}