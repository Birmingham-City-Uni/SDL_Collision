#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Player {
public:
	Player(SDL_Renderer * renderer);
	virtual ~Player();

	bool init();

	void processInput(bool * keyDown);

	void update();

	void draw();

	void clean();

private:
	SDL_Renderer * renderer;
	SDL_Texture * playerTexture;
	float rotationAngle;

};