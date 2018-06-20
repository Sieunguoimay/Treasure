#ifndef STATE_H
#define STATE_H

#include"SDL2/SDL.h"
#include"../Handler.h"
class State{
public:
	static State* currentState;
	static void setState(State*state);
	static State* getState();
	//CLASS
	State(Handler*handler);
	virtual ~State();
	virtual void update() = 0;
	virtual void render(SDL_Renderer*renderer) = 0;
protected:
	Handler*handler;
};
#endif//STATE_H