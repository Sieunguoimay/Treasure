#include"Assets.h"
#include<sstream>
#include<fstream>
std::vector<int> AssetsManager::player_up;
std::vector<int> AssetsManager::player_down;
std::vector<int> AssetsManager::player_left;
std::vector<int> AssetsManager::player_right;
AssetsManager::AssetsManager(){

}
AssetsManager::~AssetsManager(){
	for(auto&t:textureMap){
		SDL_Log("deleted texture %s",t.first.c_str());
		delete t.second;
	}
}
AssetsManager&AssetsManager::Instance(){
	static AssetsManager assets;
	return assets;
}
void AssetsManager::init(SDL_Renderer*renderer){
	loadTexture(renderer,"../Treasure/assets/textures/names.txt");

	for(int i = 0; i<9; i++){
		player_up.push_back(i);
		player_left.push_back(i+1*9);
		player_down.push_back(i+2*9);
		player_right.push_back(i+3*9);
	}
}
void AssetsManager::loadTexture(SDL_Renderer*renderer,std::string path){
	std::ifstream file(path.c_str());
	std::string line,name;
	int pos = path.find_last_of("/\\");
	path.erase(pos+1);

	if(file.is_open()){
		while(std::getline(file,line)){
			if(line.empty())
				continue;
			int row = 1, col = 1;
			std::stringstream ss;
			ss.str(line);
			ss>>name;
			ss>>row;
			ss>>col;
			Texture*texture = new Texture(renderer,path+name,row,col);

			pos = name.find('.');
			if(pos>=0&&pos<name.size())
				name.erase(pos,name.size()-pos);
			SDL_Log("%s %i %i",name.c_str(),row,col);
			textureMap[name] = texture;
		}
		file.close();
	}
	SDL_Log("Number of loaded textures: %i",(int)textureMap.size());

}
Texture&AssetsManager::getSprite(std::string name,int index){
	index = std::min(textureMap[name]->getSpriteNum()-1,index);
	textureMap[name]->setIndex(index);
	return *textureMap[name];
}
Texture&AssetsManager::getNextSprite(std::string name){
	int index = textureMap[name]->getIndex()+1;
	if(index >= textureMap[name]->getSpriteNum())
		index = 0;
	textureMap[name]->setIndex(index);
	return *textureMap[name];
}
