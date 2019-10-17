#pragma once

#include <SDL.h>
#include <SDL_image.h>


class GameBackground {
public:
	GameBackground(SDL_Renderer * renderer);
	virtual ~GameBackground();

	bool init();

	void update();

	void drawBackground();
	void drawForeground();

	void clean();

private:
	SDL_Renderer * renderer;

	SDL_Texture * woodBackground;
	SDL_Texture * grassBackground;
	SDL_Texture * pineTree;

	SDL_Texture * curtainTop;
	SDL_Texture * curtainStraight;
	SDL_Texture * curtain;
	SDL_Texture * curtainRope;

};