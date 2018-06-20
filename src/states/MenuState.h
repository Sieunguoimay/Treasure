#ifndef MENU_STATE_H
#define MENU_STATE_H

#include"State.h"
class MenuState:public State{
public:
	MenuState(Handler*handler)
	:State(handler)
	{}	

	void update(){

	}
	void render(SDL_Renderer*renderer){

	}
};

#endif//MENU_STATE_H