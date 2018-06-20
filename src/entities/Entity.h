#ifndef ENTITY_H
#define ENTITY_H
#include<SDL2/SDL.h>
#include"../2d/vec2.h"
#include"../Handler.h"
class Entity{
protected:
	Handler*handler;
	vec2 pos;
	Size size;
	Rectangle bounds;
public:
	Entity(Handler*handler, float x, float y, int width, int height)
		:handler(handler),pos(x,y),size(width,height)
		,bounds(0,0,width, height)
	{}
	virtual ~Entity(){
		handler = NULL;
	}
	virtual void update() = 0;
	virtual void render(SDL_Renderer*renderer) = 0;

	//Getters and Setters
	vec2&getPos(){return pos;}
	void setPos(float x, float y){pos.set(x,y);}

	void setSize(float w, float h){size.set(w,h);}
	Size&getSize(){return size;}

	bool checkEntityCollision(float xOffet, float yOffset);
	Rectangle getCollisionBounds(float xOffset, float yOffset){
		return Rectangle((pos.x+bounds.x+xOffset),(pos.y+bounds.y+yOffset),bounds.w,bounds.h);
	}
};
#endif//ENTITY_H