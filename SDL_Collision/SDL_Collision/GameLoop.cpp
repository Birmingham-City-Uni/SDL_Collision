#include "GameLoop.h"

GameLoop::GameLoop()
{

}

bool GameLoop::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Could not initialise SDL: " << SDL_GetError();
		return false;
	}
	window = SDL_CreateWindow(
		"SDL - Collision detection",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480,
		SDL_WINDOW_SHOWN
	);

	if (!window) {
		std::cerr << "Could not create SDL window: " << SDL_GetError();
		return false;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cout << "Error creating renderer:" << SDL_GetError() << std::endl;
		return false;
	}

	for (int i = 0; i < 256; i++) {
		keyDown[i] = false;
	}

	gameBackground = new GameBackground(this->renderer);
	gameBackground->init();

	return true;

}

bool GameLoop::processInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			//check against array size to prevent writing outside the bounds
			if (e.key.keysym.scancode < 512) {
				keyDown[e.key.keysym.scancode] = true;
			}
		}
		else if (e.type == SDL_KEYUP) {
			//check against array size to prevent writing outside the bounds
			if (e.key.keysym.scancode < 512) {
				keyDown[e.key.keysym.scancode] = false;
			}
		}

	}

	return true;
}

void GameLoop::update()
{
	gameBackground->update();
}

void GameLoop::draw()
{
	SDL_RenderClear(renderer);

	gameBackground->drawBackground();

	gameBackground->drawForeground();

	SDL_RenderPresent(renderer);
	SDL_Delay(16);
}

void GameLoop::clean()
{
	gameBackground->clean();
}
