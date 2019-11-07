#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "BulletManager.h"

using namespace std;

struct Meteor {
	int x, y;
};

class MeteorManager {

public:
	MeteorManager(SDL_Renderer * renderer, BulletManager * bulletManager) : renderer(renderer), bulletManager(bulletManager) {}
	virtual ~MeteorManager() { }

	void init() {
		SDL_Surface * surface = IMG_Load("cache/meteor.png");
		this->meteorTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
		SDL_FreeSurface(surface);

		for (int i = 0; i < MAX_METEORS; i++) {
			meteors.push_back(Meteor{  rand() % 640, rand() % 480 });
		}
	}

	void update() {
		for (auto &m : meteors) {
			m.x += 1;
			if (m.x > 640 + 32) {
				m.x = -32;
			}
			for (auto &b : bulletManager->bullets) {
				SDL_Rect bulletRect = { b.x, b.y, 10, 10 };
				SDL_Rect meteorRect = { m.x, m.y, 32, 32 };
				SDL_Rect nullRect;
				if (SDL_IntersectRect(&bulletRect, &meteorRect, &nullRect)) {
					b.distance = 1000; //this makes the bullet get removed
					m.x = 0xCCCCCCCC; //this is checked later to move the meteor
				}
			}
		}
		if (meteors.size() < MAX_METEORS) {
			meteors.push_back(Meteor{ -32, rand() % 480 });
		}
		
		auto remove = std::remove_if(meteors.begin(), meteors.end(), [](const Meteor& m) { return m.x == 0xCCCCCCCC; });
		meteors.erase(remove, meteors.end());
	}

	void draw() {
		for (auto &m : meteors) {
			SDL_Rect dest = { m.x, m.y, 32,32, };
			SDL_RenderCopy(renderer, meteorTexture, 0, &dest);
		}
	}
	void clean() {
		SDL_DestroyTexture(this->meteorTexture);
	}

private:
	vector<Meteor> meteors;
	SDL_Renderer * renderer;
	SDL_Texture * meteorTexture;
	BulletManager * bulletManager;

	const int MAX_METEORS = 16;
};