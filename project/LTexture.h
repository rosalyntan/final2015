// Class that deals with SDL textures

#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

//Texture wrapper class
class LTexture {
	public:
		LTexture();
		~LTexture();
		bool loadFromFile(string path, SDL_Renderer* gRenderer); // loads image at specified path
		bool loadFromRenderedText(string textureText, SDL_Color textColor, SDL_Renderer* gRenderer, TTF_Font* gFont);
		void free(); // deallocates texture
		void render(int x, int y, SDL_Rect* clip = NULL, SDL_Renderer* renderer=NULL); // renders texture at given point
		// gets image dimensions
		int getWidth();
		int getHeight();
		SDL_Texture* getTexture(); // might need to remove
	private:
		SDL_Texture* mTexture; // actual hardware texture
		// image dimensions
		int mWidth;
		int mHeight;
};

#endif
