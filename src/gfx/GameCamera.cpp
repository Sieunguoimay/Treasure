#include"GameCamera.h"
#include"../entities/Entity.h"
#include"../Game.h"
GameCamera::GameCamera(Handler*handler,float xOffset, float yOffset)
	:handler(handler),offset(xOffset,yOffset){}

void GameCamera::centerOnEntity(Entity *e){
	offset.x = e->getPos().x +e->getSize().w/2 - handler->getGame()->getSize().w/2;
	offset.y = e->getPos().y +e->getSize().h/2 - handler->getGame()->getSize().h/2;
	//SDL_Log("%f + %f",offset.x,offset.y);
}
void GameCamera::move(float xAmt, float yAmt){
	this->offset.x+=xAmt;
	this->offset.y+=yAmt;
}
