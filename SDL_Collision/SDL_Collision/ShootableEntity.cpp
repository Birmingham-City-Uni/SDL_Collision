#include "ShootableEntity.h"

ShootableEntity::ShootableEntity(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

ShootableEntity::~ShootableEntity()
{
}

bool ShootableEntity::init()
{
	srand(time(NULL));
	//select random graphics index
	int spriteIndex = rand() % 5;
	int shotIndex = rand() % 8;
	int stickIndex = rand() % 3;
	std::string spriteFilePath = "cache/objects/" + entitySprites[spriteIndex];
	std::string shotFilePath = "cache/objects/" + shotSprites[shotIndex];
	std::string stickFilePath = "cache/objects/" + sickSprites[stickIndex];

	SDL_Surface * surface = IMG_Load(spriteFilePath.c_str());
	this->entitySprite = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load(shotFilePath.c_str());
	this->shotSprite = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	surface = IMG_Load(stickFilePath.c_str());
	this->stickSprite = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);

	SDL_QueryTexture(this->entitySprite, 0, 0, &this->entityW, &this->entityH);

	x = 100;
	y = 100;

	return false;
}

void ShootableEntity::update()
{
}

void ShootableEntity::draw()
{
	SDL_Rect r = { this->x, this->y, this->entityW, this->entityH };
	SDL_RenderCopy(this->renderer, this->entitySprite, 0, &r);

	r = { this->x + ((this->entityW / 2) - 15), this->y + (this->entityH - 5), 30, 123 };
	SDL_RenderCopy(this->renderer, this->stickSprite, 0, &r);
}

void ShootableEntity::clean()
{
	SDL_free(entitySprite);
	SDL_free(shotSprite);
	SDL_free(stickSprite);
}
