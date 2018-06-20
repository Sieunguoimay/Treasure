#ifndef TILE_H
#define TILE_H

#include"../gfx/Texture.h"
#include<string>
#include<vector>
#include"../gfx/Assets.h"
class Tile{
protected:
	std::string texture;
	int id;
public:

	//STATIC STUFF HERE

	static std::vector<Tile*> tiles;

	static Tile*grassTile;
	static Tile*dirtTile;
	static Tile*rockTile;

	//CLASS

	const int TILEWIDTH = 64, TILEHEIGHT = 64;
	Tile(std::string texture="", int id=-1)
		:texture(texture),id(id)
	{
		tiles[id] = this;
	}
	virtual ~Tile(){
		for(int i = 0; i<tiles.size(); i++){
			delete tiles[i];
			tiles[i] = NULL;
		}
	}
	void update(){

	}
	void render(SDL_Renderer*renderer, float x, float y){
		Assets.getSprite(texture,id).render(renderer, x,y,TILEWIDTH, TILEHEIGHT,0);
	}
	virtual bool isSolid()const {
		return false;
	}
	int getId()const{
		return id;
	}
};
#endif//TILE_H