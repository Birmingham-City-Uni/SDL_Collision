#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

using namespace std;

struct Meteor {
	int x, y;
};

class MeteorManager {

public:
	MeteorManager(SDL_Renderer * renderer) : renderer(renderer) {}
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
		}
		if (meteors.size() < MAX_METEORS) {
			meteors.push_back(Meteor{ -32, rand() % 480 });
		}
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

	const int MAX_METEORS = 16;
};