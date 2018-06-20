#include"GrassTile.h"
#include"DirtTile.h"
#include"RockTile.h"
std::vector<Tile*> Tile::tiles(256);
Tile*Tile::grassTile = new GrassTile(0);
Tile*Tile::dirtTile = new DirtTile(1);
Tile*Tile::rockTile = new RockTile(2);
