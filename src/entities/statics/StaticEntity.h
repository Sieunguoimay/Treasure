#pragma once
#include"../Entity.h"
class StaticEntity:public Entity{
public:
	StaticEntity(Handler *handler, float x, float y, float w, float h)
		:Entity(handler, x,y,w,h)
	{}	
};