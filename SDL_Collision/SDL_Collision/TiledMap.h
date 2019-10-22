#pragma once
#include <SDL.h>
#include <SDL_image.h>

//number of game tiles in the map
#define MAP_SIZE_X 6
#define MAP_SIZE_Y 5
//size that each tile is drawn in pixels
#define MAP_TILE_SIZE_PX 64

const int MAP_DATA[MAP_SIZE_Y][MAP_SIZE_X] = {
	{ 0,0,0,0,0,0 },
	{ 6,7,8,9,10,11 },
	{ 25,25,25,25,25,25 },
	{ 25,25,25,25,25,25 },
	{ 25,25,25,25,25,25 },
};

class TiledMap {
public:
	TiledMap(SDL_Renderer * renderer) {
		this->renderer = renderer;
	}
	~TiledMap() {}

	void init() {
		//all of the tiles are within one texture
		SDL_Surface * s = IMG_Load("cache/map.png");
		this->mapTileset = SDL_CreateTextureFromSurface(this->renderer, s);
		SDL_FreeSurface(s);
	}

	void draw() {
		for (int i = 0; i < MAP_SIZE_Y; i++) {
			for (int j = 0; j < MAP_SIZE_X; j++) {
				//calculate the area of the texture which needs to be drawn
				SDL_Rect srcRect = { (MAP_DATA[i][j] % 6)*70, ((MAP_DATA[i][j]) / 6) *70, 70, 70 };
				//calculate location it needs to be drawn to the screen
				SDL_Rect destRect = {j*MAP_TILE_SIZE_PX, i*MAP_TILE_SIZE_PX, MAP_TILE_SIZE_PX, MAP_TILE_SIZE_PX};
				SDL_RenderCopy(renderer, mapTileset, &srcRect, &destRect);
			}
		}
	}

	void cleanUp() {
		SDL_DestroyTexture(mapTileset);
	}

private:
	SDL_Renderer * renderer;
	SDL_Texture * mapTileset;
};