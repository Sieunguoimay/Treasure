#include"Creature.h"
#include"../../worlds/World.h"
int Creature::DEFAULT_HEALTH = 10;
float Creature::DEFAULT_SPEED = 3.0f;
int Creature::DEFAULT_CREATURE_WIDTH = 64;
int Creature::DEFAULT_CREATURE_HEIGHT = 64;

void Creature::move(){

	if(!checkEntityCollision(0, 0.0f))
		moveX();

	if(!checkEntityCollision(0.0f,0))
		moveY();

}
void Creature::moveX(){
	if(vel.x>0){//move right
		int tx = (int)(pos.x+vel.x+bounds.x+bounds.w)/Tile::grassTile->TILEWIDTH;
		if(!collisionWithTile(tx,(int)(pos.y+bounds.y)/Tile::grassTile->TILEHEIGHT)
			&&!collisionWithTile(tx,(int)(pos.y+bounds.y+bounds.h)/Tile::grassTile->TILEHEIGHT)){
			pos.x+=vel.x;
		}else{
			pos.x = tx*Tile::grassTile->TILEWIDTH - bounds.x-bounds.w-1;
		}
	}else if(vel.x<0){//move left
		int tx = (int)(pos.x+vel.x+bounds.x)/Tile::grassTile->TILEWIDTH;
		if(!collisionWithTile(tx,(int)(pos.y+bounds.y)/Tile::grassTile->TILEHEIGHT)
			&&!collisionWithTile(tx,(int)(pos.y+bounds.y+bounds.h)/Tile::grassTile->TILEHEIGHT)){
			pos.x+=vel.x;
		}else{
			pos.x = tx*Tile::grassTile->TILEWIDTH+Tile::grassTile->TILEWIDTH - bounds.x;
		}
	}
}
void Creature::moveY(){
	if(vel.y>0){//move down
		int ty = (int)(pos.y+vel.y+bounds.y+bounds.h)/Tile::grassTile->TILEHEIGHT;
		if(!collisionWithTile((int)(pos.x+bounds.x)/Tile::grassTile->TILEWIDTH,ty)
			&&!collisionWithTile((int)(pos.x+bounds.x+bounds.w)/Tile::grassTile->TILEWIDTH,ty)){
			pos.y+=vel.y;
		}else{
			pos.y = ty*Tile::grassTile->TILEHEIGHT - bounds.y-bounds.h-1;
		}
	}else if(vel.y<0){//move up
		int ty = (int)(pos.y+vel.y+bounds.y)/Tile::grassTile->TILEHEIGHT;
		if(!collisionWithTile((int)(pos.x+bounds.x)/Tile::grassTile->TILEWIDTH,ty)
			&&!collisionWithTile((int)(pos.x+bounds.x+bounds.w)/Tile::grassTile->TILEWIDTH,ty)){
			pos.y+=vel.y;
		}else{
			pos.y = ty*Tile::grassTile->TILEHEIGHT+Tile::grassTile->TILEHEIGHT - bounds.y;

		}
	}
}


bool Creature::collisionWithTile(int x, int y){
	return handler->getWorld()->getTile(x,y)->isSolid();
}

