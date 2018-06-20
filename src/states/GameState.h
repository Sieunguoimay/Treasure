#ifndef GAME_STATE_H
#define GAME_STATE_H
#include<SDL2/SDL.h>
#include"State.h"
#include"../gfx/Assets.h"
#include"../tiles/Tile.h"
#include"../worlds/World.h"
//this is where every game entities live
class GameState: public State{
	World*world;
public:
	GameState(Handler*handler)
		:State(handler){
		world = new World(handler,"assets/worlds/world1.txt");
		handler->setWorld(world);
		//player = new Player(handler,100,100);
		//tree = new Tree(handler,100,200);
	}
	~GameState(){
		//delete tree;
		//tree = NULL;
		//delete player;
		//player = NULL;
		delete world;
		world = NULL;
	}
	void update(){
		//player->update();
		world->update();
	}
	void render(SDL_Renderer*renderer){
		world->render(renderer);
		//player->render(renderer);
		//tree->render(renderer);
	}
};

#endif//GAME_STATE_H