#pragma once

#include<vector>
#include"Entity.h"
#include"creatures/Player.h"
#include"statics/Tree.h"
class EntityManager{
	Handler*handler;
	Player*player;	
	std::vector<Entity*>entities;


public:
	EntityManager(Handler*handler,Player*player)
		:handler(handler), player(player)
	{
		addEntity(player);
		addEntity(new Tree(handler,200,250));
	}
	void update(){
		for(auto&a:entities)
			a->update();
	}
	void render(SDL_Renderer*renderer){
		for(auto&a:entities)
			a->render(renderer);		
	}
	void addEntity(Entity*e){
		entities.push_back(e);
	}
	//getter & setters
	Player*getPlayer(){return this->player;}
	std::vector<Entity*>&getEntities(){return this->entities;}
};