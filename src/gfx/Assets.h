//Singleton

#ifndef ASSETS_H
#define ASSETS_H
#include<string>
#include<map>
#include<vector>
#include"Texture.h"
#define TextureMap std::map<std::string,Texture*>
class AssetsManager{
	AssetsManager();
	//this assignment need to be private
	AssetsManager(const AssetsManager&);
	AssetsManager&operator=(const AssetsManager&);
	TextureMap textureMap;

public:
	static std::vector<int>player_up,player_down,player_left, player_right;
	static AssetsManager&Instance();
	~AssetsManager();
	void init(SDL_Renderer*renderer);
	void loadTexture(SDL_Renderer*renderer,std::string path);
	Texture&getSprite(std::string name, int index);
	Texture&getNextSprite(std::string name);
};
#define Assets AssetsManager::Instance()
#endif//ASSETS_H