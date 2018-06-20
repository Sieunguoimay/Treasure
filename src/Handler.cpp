#include"Handler.h"
#include"Game.h"

Handler::Handler(Game*game)
	:game(game){}


Handler::~Handler(){
	game = NULL;
}

void Handler::setGame(Game*game){
	this->game = game;
}
Game*Handler::getGame(){
	return game;
}	

void Handler::setWorld(World*world){
	this->world = world;
}
World*Handler::getWorld(){
	return this->world;
}
GameCamera*Handler::getGameCamera(){
	return game->getGameCamera();
}

Size&Handler::getSize(){
	return game->getSize();
}
