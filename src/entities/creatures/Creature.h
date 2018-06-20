#ifndef CREATURE_H
#define CREATURE_H
#include"../Entity.h"
class Creature: public Entity{
protected:
	int health;
	float speed;
	vec2 vel;
public:
	static int DEFAULT_HEALTH;
	static float DEFAULT_SPEED;
	static int 	DEFAULT_CREATURE_WIDTH,
				DEFAULT_CREATURE_HEIGHT;

public:
	Creature(Handler*handler,float x, float y, int width, int height)
		:Entity(handler,x,y,width, height)
	{
		health = DEFAULT_HEALTH;
		speed = DEFAULT_SPEED;
		vel.zero();
	}
	void move();
	void moveX();
	void moveY();
	
	bool collisionWithTile(int x, int y);
	void setHealth(int health){this->health = health;}
	void setSpeed(float speed){this->speed = speed;}
	void setVel(float x, float y){vel.set(x,y);}
	void setVel(vec2 v){vel.x = v.x; vel.y = v.y;}

	int getHealth()const{return health;}
	float getSpeed()const{return speed;}
	vec2 getVel()const{return vel;}
};

#endif//CREATURE_H