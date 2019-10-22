#pragma once

#include <string>
#include <stdlib.h>
#include <time.h> 

#include <SDL.h>
#include <SDL_image.h>


const std::string entitySprites[] = { "duck_outline_target_brown.png", "duck_outline_brown.png", 
"duck_outline_target_white.png", "duck_outline_target_yellow.png", "duck_outline_yellow.png", "target_colored.png", "target_red1.png", 
"target_red2.png", "target_red3.png", "target_white.png" };
const std::string shotSprites[] = {  "shot_blue_large.png", "shot_blue_small.png", "shot_brown_large.png", "shot_brown_small.png",
"shot_grey_large.png", "shot_grey_small.png", "shot_yellow_large.png", "shot_yellow_small.png"};
const std::string sickSprites[] = { "stick_metal.png", "stick_wood.png", "stick_woodFixed.png" };

class ShootableEntity {
public:
	ShootableEntity(SDL_Renderer * renderer);
	virtual ~ShootableEntity();

	bool init();

	void update();

	void draw();

	void clean();

private:
	SDL_Renderer * renderer;

	SDL_Texture * entitySprite;
	SDL_Texture * shotSprite;
	SDL_Texture * stickSprite;

	int x, y;
	int entityW, entityH;
};