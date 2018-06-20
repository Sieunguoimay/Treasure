
#ifndef WORLD_H
#define WORLD_H
#include<string>
#include<fstream>
#include<sstream>
#include"../2d/vec2.h"
#include"../tiles/Tile.h"
#include"../Game.h"
#include"../entities/EntityManager.h"
class World{
private:
	int spawnX, spawnY;
	int width, height;
	Handler*handler;
	std::vector<std::vector<int>> tiles;

	EntityManager*entityManager;

	void loadWorld(std::string path){
		std::string line;
		std::ifstream file(path.c_str());
		int a = -1;
		if(file.is_open()){
			std::stringstream buffer;
			buffer<<file.rdbuf();
			file.close();

			buffer>>width;
			buffer>>height;

			buffer>>spawnX;
			buffer>>spawnY;

			tiles = std::vector<std::vector<int>>(width,std::vector<int>(height));
			for(int y = 0; y<height; y++){
				for(int x = 0; x<width; x++){
					buffer>>tiles[x][y];
				}
			}
		}		
	}
public:
	World(Handler*handler,std::string path)
		:handler(handler)
	{
		entityManager = new EntityManager(handler,new Player(handler,200,100));
		loadWorld(path);
		entityManager->getPlayer()->setPos(spawnX,spawnY);
	}
	void update(){
		entityManager->update();
	}
	void render(SDL_Renderer*renderer){
		
		int xStart = (int)std::max(0.0f,handler->getGameCamera()->getOffset().x/float(Tile::grassTile->TILEWIDTH));
		int xEnd = (int)std::min((float)width,
			(handler->getGameCamera()->getOffset().x + handler->getSize().w)/float(Tile::grassTile->TILEWIDTH)+1.0f);
		int yStart = (int)std::max(0.0f,handler->getGameCamera()->getOffset().y/float(Tile::grassTile->TILEHEIGHT));
		int yEnd = (int)std::min((float)height,
			(handler->getGameCamera()->getOffset().y + handler->getSize().h)/float(Tile::grassTile->TILEHEIGHT)+1.0f);

		for(int x = xStart; x<xEnd; x++){
			for(int y = yStart; y<yEnd; y++){
				Tile*t = getTile(x,y);
				t->render(renderer,(int)(x*t->TILEWIDTH-handler->getGameCamera()->getOffset().x),
				 					(int)(y*t->TILEHEIGHT-handler->getGameCamera()->getOffset().y));
			}
		}
		entityManager->render(renderer);
	}
	Tile*getTile(int x, int y){
		if(x<0||y<0||x>=width||y>=height)
			return Tile::grassTile;
		Tile*t = Tile::tiles[tiles[x][y]];
		if(t == NULL){
			return Tile::dirtTile;
		}
	}
	EntityManager*getEntityManager(){return this->entityManager;}
};
#endif//WORLD_H