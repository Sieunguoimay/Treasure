//Let's make it a singleton
#ifndef KEY_MANAGER_H
#define KEY_MANAGER_H
#include<SDL2/SDL.h>
class KeyManager{
	const Uint8*state;

	KeyManager(){}

	//assignment need tobe private
	KeyManager(const KeyManager&);
	KeyManager&operator=(const KeyManager&);
public:
	bool up,down,left,right;
	//Singleton
	static KeyManager&Instance();
	~KeyManager(){
	}
	void update(){
		state = SDL_GetKeyboardState(NULL);
		up = state[SDL_SCANCODE_UP];
		down = state[SDL_SCANCODE_DOWN];
		left = state[SDL_SCANCODE_LEFT];
		right = state[SDL_SCANCODE_RIGHT];
	}
};

//to make life easier..
#define KeyPressed KeyManager::Instance()
#endif//KEY_MANAGER_H