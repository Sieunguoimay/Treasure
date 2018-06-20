#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H
#include"../2d/vec2.h"
#include"../Handler.h"
class Entity;
class GameCamera{
	vec2 offset;
	Handler*handler;
public:
	GameCamera(Handler*handler,float xOffset, float yOffset);

	void centerOnEntity(Entity*e);
	void move(float xAmt,float yAmt);

	//SETTERS and GETTERS
	void setOffset(float xOffset, float yOffset){
		this->offset.set(xOffset,yOffset);
	}
	vec2&getOffset(){
		return this->offset;
	}
};
#endif//GAME_CAMERA_H