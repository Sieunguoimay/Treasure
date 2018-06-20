#include"Texture.h"
Texture::Texture(SDL_Renderer*renderer,std::string path, int row, int col)
	:row(row),col(col)
{
	index = 0;
	SDL_Surface*loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface){
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xff, 0x00, 0xff));//always pink
		texture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
		sprite.w = loadedSurface->w / col;
		sprite.h = loadedSurface->h / row;
		//position of the sprite on the texture decides the sprite
		sprite.x = 0;
		sprite.y = 0;
		SDL_Log("Loaded texture: %s", path.c_str());
	}
	SDL_FreeSurface(loadedSurface);
}
Texture::~Texture(){
	SDL_DestroyTexture(texture);
	texture = NULL;
}
void Texture::render(SDL_Renderer*renderer, int x, int y, int w, int h,double angle,bool flip){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderCopyEx(renderer,texture,&sprite,&rect,angle,NULL,(flip?SDL_FLIP_VERTICAL:SDL_FLIP_NONE));
}
void Texture::setIndex(int index){
	this->index = index;
	if(index<getSpriteNum()){
		sprite.x = (index%col)*sprite.w;
		sprite.y = (index/col)*sprite.h;
	}
}
int Texture::getIndex() const{
	return index;
}

int Texture::getSpriteNum(){
	return row*col;
}
