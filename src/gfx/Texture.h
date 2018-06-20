#ifndef TEXTURE_H
#define TEXTURE_H
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
class Texture{
	SDL_Texture*texture;
	SDL_Rect sprite;
	int row, col;
	int index;
public:
	Texture(SDL_Renderer*renderer,std::string path, int row = 1, int col = 1);
	~Texture();
	void render(SDL_Renderer*renderer,int x, int y,int w, int h, double angle,bool flip = false);
	void setIndex(int index);
	int getIndex() const ;
	int getSpriteNum();
};
#endif//TEXTURE_H
