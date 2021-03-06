#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <ctime>
#include "LTexture.h"
using namespace std;

class Background {
	public:
		Background();
		~Background();
		void turn(int); //function replaces switch case that randomly generates turns
		void frames(); //determines what frames are shown depending on the results of turn() function
		bool lose(int);
		int getNumTurn();
		bool loadMedia(SDL_Renderer*, SDL_Window*);
		void display(int, int, SDL_Renderer*);
		int getFrameBack();
	private:
		//int random; //random number generated for turn
		//int difficulty; //used with random number generator, can be decreased to make game harder
		int frameBack;
		int dirTurn;
		int numTurn;
		int prev;
		SDL_Rect* currentClipBack;
		bool quit;
//		int BACKGROUND_ANIMATION_FRAMES;
		SDL_Rect gBackClips[13];
		LTexture gSpriteSheetTexture;
};

#endif
