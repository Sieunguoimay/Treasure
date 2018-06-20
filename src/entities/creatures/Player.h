#ifndef PLAYER_H
#define PLAYER_H
#include"Creature.h"
#include"../../gfx/Animation.h"

class Player:public Creature{
	Animation*animUp,*animDown,*animLeft,*animRight,*currentAnimation;
	void getInput();
public:
	Player(Handler*handler,float x, float y);
	~Player();
	void update();
	void render(SDL_Renderer*renderer);
};
#endif//PLAYER_H