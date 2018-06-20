#ifndef HANDLER_H
#define HANDLER_H
#include"2d/vec2.h"
class World;
class Game;
class GameCamera;
class Handler{
	Game*game;//pointer
	World*world;
public:
	Handler(Game*game);
	~Handler();


	void setGame(Game*game);
	Game*getGame();
	void setWorld(World*world);
	World*getWorld();
	GameCamera*getGameCamera();
	Size&getSize();

};

#endif//HANDLER_H