#include "Player.h"
Player::Player(SDL_Renderer * renderer) {
	this->renderer = renderer;
	this->rotationAngle = 0.0f;
}
Player::~Player()
{
}

bool Player::init()
{
	SDL_Surface * surface = IMG_Load("cache/player.png");
	this->playerTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);

	return false;
}

void Player::processInput(bool * keyDown)
{
	if (keyDown[SDL_SCANCODE_LEFT]) {
		this->rotationAngle -= 2.0f;
	}
	if (keyDown[SDL_SCANCODE_RIGHT]) {
		this->rotationAngle += 2.0f;
	}
}

void Player::update()
{

}

void Player::draw()
{
	SDL_Rect r = { 640/2-(98/4), 480/2-(75/4), 98/2, 75/2 };
	SDL_Point rotationCenter = { 98/4,75/4 };
	SDL_RenderCopyEx(this->renderer, this->playerTexture, 0, &r, this->rotationAngle, &rotationCenter, SDL_FLIP_NONE);
}

void Player::clean()
{
	SDL_DestroyTexture(this->playerTexture);
}
