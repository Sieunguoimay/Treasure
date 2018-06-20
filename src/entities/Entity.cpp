#include"Entity.h"
#include"EntityManager.h"
#include"../worlds/World.h"
bool Entity::checkEntityCollision(float xOffet, float yOffset){
	for(auto&e:handler->getWorld()->getEntityManager()->getEntities()){
		if(e == this)
			continue;
		if(e->getCollisionBounds(0.0f,0.0f).intersects(getCollisionBounds(xOffet,yOffset))){
			return true;
		}
	}
	return false;
}
