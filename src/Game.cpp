#include"Game.h"
#include"states/GameState.h"
#include"states/MenuState.h"
#include"input/KeyManager.h"
#include"gfx/Assets.h"
//#include"gfx/GameCamera.h"
#include"Handler.h"

Game::Game(std::string title, int width, int height)
	:title(title),size(width, height)
{

}
Game::~Game(){
	delete menuState;
	menuState = NULL;
	delete gameState;
	gameState = NULL;

//	delete gameCamera;
//	gameCamera = NULL;

	delete handler;
	handler = NULL;
	delete display;
	display = NULL;
}
void Game::init(){
	display = new Display(title,size.w, size.h);
	Assets.init(display->getRenderer());
	handler = new Handler(this);

	gameCamera = new GameCamera(handler,0,0);

	gameState = new GameState(handler);
	menuState = new MenuState(handler);
	State::setState(gameState);
}
void Game::update(){
	KeyPressed.update();
	if(State::getState()!=NULL){
		State::getState()->update();
	}
}
void Game::render(){
	renderer = display->getRenderer();
	SDL_SetRenderDrawColor(renderer,0xee,0xee,0xee,0xff);
	SDL_RenderClear(renderer);
	//Draw here..

	if(State::getState()!=NULL){
		State::getState()->render(renderer);
	}

	SDL_RenderPresent(renderer);
}
void Game::run(){
	init();
	int fps = 60;
	double timePerTick = 1000.0/(double)fps;
	double delta = 0;
	long currentTime;
	long lastTime = SDL_GetTicks();
	long timer = 0;
	int ticks = 0;
	while(running){

		currentTime = SDL_GetTicks();
		delta += (double)(currentTime-lastTime)/timePerTick;
		timer += currentTime - lastTime;
		lastTime = currentTime;

		if(delta>=1.0){

			//update here..
			display->handleEvent();
			if(display->isForcedExit())
				running = false;
			update();
			render();



			delta--;
			ticks++;
		}

		if(timer>=1000.0){
			// SDL_Log("%d",ticks);
			ticks = 0;
			timer = 0;
		}
	}
}
GameCamera*Game::getGameCamera(){return this->gameCamera;}
Size& Game::getSize(){return this->size;}
