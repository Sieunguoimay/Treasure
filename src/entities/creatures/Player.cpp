#include"Player.h"
#include"../../input/KeyManager.h"
#include"../../gfx/Assets.h"
#include"../../Game.h"

Player::Player(Handler*handler,float x, float y)
	:Creature(handler,x,y,Creature::DEFAULT_CREATURE_WIDTH,Creature::DEFAULT_CREATURE_HEIGHT)
{

	bounds.x = 16;
	bounds.y = 32;
	bounds.w = 32;
	bounds.h = 32;

	animUp = new Animation(50,&Assets.player_up);
	animDown = new Animation(50,&Assets.player_down);
	animLeft = new Animation(50,&Assets.player_left);
	animRight = new Animation(50,&Assets.player_right);
	currentAnimation = animDown;
}	
Player::~Player(){
	delete animUp;
	delete animDown;
	delete animLeft;
	delete animRight;
}
void Player::getInput(){
	vel.zero();
	if(KeyPressed.up){
		vel.y = -speed;
		currentAnimation = animUp;
	}
	if(KeyPressed.down){
		vel.y = speed;
		currentAnimation = animDown;
	}
	if(KeyPressed.left){
		vel.x = -speed;
		currentAnimation = animLeft;
	}
	if(KeyPressed.right){
		vel.x = speed;
		currentAnimation = animRight;
	}
}
void Player::update(){
	currentAnimation->update();
	getInput();
	move();
	handler->getGameCamera()->centerOnEntity(this);
}
void Player::render(SDL_Renderer*renderer){

	Assets.getSprite("player",currentAnimation->getCurrentFrame()).render(renderer,(int)(pos.x - handler->getGameCamera()->getOffset().x),
		(int)(pos.y - handler->getGameCamera()->getOffset().y),size.w, size.h, 0);
/*
	SDL_SetRenderDrawColor(renderer,0xff,0x00,0x00,0x00);
	SDL_Rect temp = {(int)(pos.x+bounds.x- handler->getGameCamera()->getOffset().x),(int)(pos.y+bounds.y- handler->getGameCamera()->getOffset().y),(int)bounds.w,(int)bounds.h};
	SDL_RenderFillRect(renderer,&temp);
*/
}
