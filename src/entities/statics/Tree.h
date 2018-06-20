#pragma once
#include"StaticEntity.h"
#include"../../tiles/Tile.h"
#include"../../gfx/GameCamera.h"
class Tree:public StaticEntity{
public:
	Tree(Handler* handler, float x, float y)
	:StaticEntity(handler,x,y,Tile::grassTile->TILEWIDTH*2,Tile::grassTile->TILEHEIGHT*2){
		bounds.x = 10;
		bounds.y = (int)size.w/2;
		bounds.w = (int)size.w/2;
		bounds.h = (int)size.h/3;
	}
	void update(){

	}
	void render(SDL_Renderer*renderer){
		Assets.getSprite("tree",0).render(renderer, (int)(pos.x-handler->getGameCamera()->getOffset().x),
				 					(int)(pos.y-handler->getGameCamera()->getOffset().y)
				 					,size.w,size.h,0);
		Rectangle b = getCollisionBounds(0,0);
		SDL_Rect r={(int)(b.x-handler->getGameCamera()->getOffset().x),(int)(b.y-handler->getGameCamera()->getOffset().y),(int)b.w, (int)b.h};
		SDL_RenderFillRect(renderer,&r);
	}
};