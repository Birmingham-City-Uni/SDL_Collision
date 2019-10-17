#include "GameBackground.h"

GameBackground::GameBackground(SDL_Renderer * renderer) {
	this->renderer = renderer;
}

GameBackground::~GameBackground()
{
}

bool GameBackground::init()
{
	SDL_Surface * surface = IMG_Load("cache/Stall/bg_wood.png");
	this->woodBackground = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("cache/Stall/grass1.png");
	this->grassBackground = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("cache/Stall/tree_pine.png");
	this->pineTree = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("cache/Stall/curtain.png");
	this->curtain = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("cache/Stall/curtain_straight.png");
	this->curtainStraight = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("cache/Stall/curtain_top.png");
	this->curtainTop = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("cache/Stall/curtain_rope.png");
	this->curtainRope = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);

	return false;
}

void GameBackground::update()
{
}

void GameBackground::drawBackground()
{
	SDL_Rect r = { 0,0,640/2,480/2 };
	SDL_RenderCopy(this->renderer, this->woodBackground, 0, &r);
	r = { 320,0,640 / 2,480 / 2 };
	SDL_RenderCopy(this->renderer, this->woodBackground, 0, &r);
	r = { 0,240,640 / 2,480 / 2 };
	SDL_RenderCopy(this->renderer, this->woodBackground, 0, &r);
	r = { 320,240,640 / 2,480 / 2 };
	SDL_RenderCopy(this->renderer, this->woodBackground, 0, &r);
	r = { 0,480-200,132,200 };
	SDL_RenderCopy(this->renderer, this->grassBackground, 0, &r);
	r = { 132*1,480 - 200,132,200 };
	SDL_RenderCopy(this->renderer, this->grassBackground, 0, &r);
	r = { 132 * 2,480 - 200,132,200 };
	SDL_RenderCopy(this->renderer, this->grassBackground, 0, &r);
	r = { 132 * 3,480 - 200,132,200 };
	SDL_RenderCopy(this->renderer, this->grassBackground, 0, &r);
	r = { 132 * 4,480 - 200,132,200 };
	SDL_RenderCopy(this->renderer, this->grassBackground, 0, &r);


}

void GameBackground::drawForeground()
{
	SDL_Rect r = { 20,50,200,63 };
	SDL_RenderCopy(this->renderer, this->curtainTop, 0, &r);
	r = { 200,50,200,63 };
	SDL_RenderCopy(this->renderer, this->curtainTop, 0, &r);
	r = { 380,50,200,63 };
	SDL_RenderCopy(this->renderer, this->curtainTop, 0, &r);
	r = { 0,0,120,430 };
	SDL_RenderCopy(this->renderer, this->curtain, 0, &r);
	r = { 520,0,120,430 };
	//different function here to flip curtain image
	SDL_RenderCopyEx(this->renderer, this->curtain, 0, &r,0,0,SDL_FLIP_HORIZONTAL);

	r = { 0,0,256,80 };
	SDL_RenderCopy(this->renderer, this->curtainStraight, 0, &r);
	r = { 256,0,256,80 };
	SDL_RenderCopy(this->renderer, this->curtainStraight, 0, &r);
	r = { 512,0,256,80 };
	SDL_RenderCopy(this->renderer, this->curtainStraight, 0, &r);

	r = { -5,205,35,20 };
	SDL_RenderCopy(this->renderer, this->curtainRope, 0, &r);

	r = { 640-30,205,35,20 };
	SDL_RenderCopy(this->renderer, this->curtainRope, 0, &r);
}

void GameBackground::clean()
{
	SDL_free(woodBackground);
	SDL_free(grassBackground);
	SDL_free(pineTree);

	SDL_free(curtainTop);
	SDL_free(curtainStraight);
	SDL_free(curtain);
	SDL_free(curtainRope);
}
