#ifndef GAME_H
#define GAME_H

#include<string>
#include"2d/vec2.h"
#include"display/Display.h"
#include"states/State.h"
#include"gfx/GameCamera.h"
#include"Handler.h"
class Game{
	std::string title;
	Size size;
	Display*display;
	bool running;
	SDL_Renderer*renderer;

	//States
	State*gameState;
	State*menuState;	
	//Handler
	Handler*handler;

	//Camera
	GameCamera*gameCamera;
public:
	Game(std::string title, int width, int height);
	~Game();
	void init();
	void update();
	void render();
	void run();


	//SETTERS and GETTERS
	GameCamera*getGameCamera();
	Size&getSize();
};
#endif//GAME_H