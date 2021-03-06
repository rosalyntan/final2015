#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Coin.h"
using namespace std;

// default constructor, also calls base class constructor
Coin::Coin() : Object(15, 15) {
	value = 2;	
}

// is this necessary?
Coin::~Coin() {

}

// renders a yellow square to the game window
void Coin::display(SDL_Renderer* gRenderer, SDL_Texture* background) {
	SDL_SetRenderTarget(gRenderer, background);
	SDL_Rect fillRect = {Object::getX(), Object::getY(), Object::getScale(), Object::getScale()};
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);
}

// score is sent in from main and incremented in this function, and then returned to main
int Coin::effect(int score) {
	score = score + value;
	return score;
}
