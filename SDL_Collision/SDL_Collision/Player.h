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

	//Add this function to make the angle accessible to other classes
	float getAngle() {
		return rotationAngle;
	}

private:
	SDL_Renderer * renderer;
	SDL_Texture * playerTexture;
	float rotationAngle;

};