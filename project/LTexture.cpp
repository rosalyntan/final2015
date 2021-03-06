#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "LTexture.h"
using namespace std;

// default constructor
LTexture::LTexture() {
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

// deconstructor
LTexture::~LTexture() {
	free();
}

bool LTexture::loadFromFile(string path, SDL_Renderer* gRenderer) {
	free(); // get rid of preexisting texture
	SDL_Texture* newTexture = NULL; // the final texture
	// load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL) {
		cout << "Unable to load image " << path.c_str() << ". SDL_image Error: " << IMG_GetError() << endl;
	}
	else {
		// color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		// create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if(newTexture == NULL) {
			cout << "Unable to create texture from " << path.c_str() << ". SDL Error: " << SDL_GetError() << endl;
		}
		else {
			// get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface); // get rid of old loaded surface
		loadedSurface = NULL;
	}
	// return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(string textureText, SDL_Color textColor, SDL_Renderer* gRenderer, TTF_Font* gFont) { 
	//Get rid of preexisting texture 
	free(); 

	//Render text surface 
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor ); 
	if( textSurface == NULL ) { 
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() ); 
	} 
	else { //Create texture from surface pixels 
		mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface ); 
		if( mTexture == NULL ) { 
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() ); 
		} 
		else { //Get image dimensions 
			mWidth = textSurface->w; 
			mHeight = textSurface->h; 
		} 
		
		//Get rid of old surface 
		SDL_FreeSurface( textSurface ); 
	} 
	//Return success 
	return mTexture != NULL; 
} 

void LTexture::free() {
	// free texture if it exists
	if(mTexture != NULL) { 
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y, SDL_Rect* clip, SDL_Renderer* renderer) {
	// set rendering space and render to screen
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};
	if(clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopy(renderer, mTexture, clip, &renderQuad);
}

int LTexture::getWidth() {
	return mWidth;
}

int LTexture::getHeight() {
	return mHeight;
}

/*For rendering an object on to a texture: SDL_SetRenderTarget requires an SDL_Texture as an argument, so this function returns the SDL_Texture*/
SDL_Texture* LTexture::getTexture() {
	return mTexture;
}
