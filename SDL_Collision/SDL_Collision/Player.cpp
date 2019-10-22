#include "Player.h"
Player::Player(SDL_Renderer * renderer) {
	this->renderer = renderer;
}
Player::~Player()
{
}

bool Player::init()
{
	SDL_Surface * surface = IMG_Load("cache/HUD/crosshair_blue_large.png");
	this->crosshair = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load("cache/Objects/rifle.png");
	this->rifle = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	crossHairPosition = { 0,0,50,50 };
	return false;
}

void Player::update()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	crossHairPosition.x = x - 25;
	crossHairPosition.y = 130;
}

void Player::draw()
{
	SDL_RenderCopy(this->renderer, this->crosshair, 0, &this->crossHairPosition);
	SDL_Rect r = { crossHairPosition.x + 80, 430 - (319/2), 142/2,319/2 };
	SDL_RenderCopy(this->renderer, this->rifle, 0, &r);
}

void Player::clean()
{
	SDL_DestroyTexture(this->crosshair);
	SDL_DestroyTexture(this->rifle);
}
