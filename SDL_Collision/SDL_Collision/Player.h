#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Player {
public:
	Player(SDL_Renderer * renderer);
	virtual ~Player();

	bool init();

	void update();

	void draw();

	void clean();

private:
	SDL_Renderer * renderer;

	SDL_Texture * rifle;
	SDL_Texture * crosshair;

	SDL_Rect crossHairPosition;
};