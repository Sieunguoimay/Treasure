#ifndef DISPLAY_H
#define DISPLAY_H

#include<SDL2/SDL.h>
#include<string>
class Display{
	std::string title;
	int width, height;
	SDL_Renderer*renderer;
	SDL_Window*window;
	SDL_Event event;
	bool forcedExit;
public:
	Display(std::string title, int width, int height)
		:title(title),width(width),height(height)
	{
		forcedExit = false;
		createDisplay();
	}
	~Display(){
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
		SDL_DestroyWindow(window);
		window = NULL;
	}
	void createDisplay(){
		window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width, height,SDL_WINDOW_SHOWN);
		if(window){
			SDL_Log("Created SDL Window %s",title.c_str());
			renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
		}
	}
	void handleEvent(){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT||(event.type==SDL_KEYDOWN&&event.key.keysym.sym ==SDLK_ESCAPE)){
				forcedExit = true;
			}
		}
	}
	bool isForcedExit(){
		return forcedExit;
	}
	SDL_Renderer*getRenderer(){
		return renderer;
	}
};
#endif//DISPLAY_H