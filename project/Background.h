#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "LTexture.h"
using namespace std;

class Background {
	public:
		Background();
		~Background();
		void turn(int, int); //function replaces switch case that randomly generates turns
		void frames(); //determines what frames are shown depending on the results of turn() function
		bool lose(int);
		int getNumTurn();
		bool loadMedia(SDL_Renderer*, SDL_Window*);
		void loadLogo(SDL_Renderer*);
		void loadFont(SDL_Renderer*, int);
		void display(int, int, int, SDL_Renderer*);
		void displayStart(SDL_Renderer*);
		void displayPause(SDL_Renderer*); 
		int getFrameBack();
		void resetNumTurn();
		SDL_Texture* getText();
		TTF_Font* scoreFont; 
		TTF_Font* startFont; 
		TTF_Font* pauseFont;
	private:
		int frameBack;
		int dirTurn;
		int numTurn;
		int prev;
		SDL_Rect* currentClipBack;
		SDL_Rect gBackClips[13];
		LTexture gSpriteSheetTexture;
		LTexture LogoTexture;
		LTexture ScoreTextTexture;
		LTexture StartTextTexture;
		LTexture PauseTextTexture;
};

#endif
