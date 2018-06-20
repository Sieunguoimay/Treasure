#pragma once
#include"Assets.h"
class Animation{
	int speed, index;
	std::vector<int>*frames;
	long lastTime,timer;
public:
	Animation(int speed, std::vector<int>*frames)
	:speed(speed),frames(frames),index(0){
		timer = 0;
		lastTime = SDL_GetTicks();
	}
	void update(){
		timer += SDL_GetTicks()-lastTime;
		lastTime = SDL_GetTicks();
		if(timer > speed){
			index++;
			timer = 0;
			if(index>=frames->size()){
				index = 0;
			}
		}
	}
	int getCurrentFrame(){
		return frames->at(index);
	}
};