#include"Tile.h"

class RockTile: public Tile{
public:
	RockTile(int id)
	:Tile("rock",id)
	{}
	bool isSolid()const {
		return true;
	}

};