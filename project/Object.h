//Abstract base class for objects along the path in RunND

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class Object {
	public:
		Object();
		~Object(); // is this necessary?
		virtual void display(SDL_Renderer* gRenderer, SDL_Texture* background) = 0; // pure virtual function to render objects to window
		// set functions to set x and y coordinates and size
		void setY(int);
		void setX(int);
		void setSize(int);
		// get functions
		int getX();
		int getY();
		int getSize();
		void nextFrame(); // sets up position and scale of the next frame for the flex point
		int getFrame();
		virtual int effect(int) = 0; // pure virtual function that increments/decrements score based on what kind of object it is
	private:
		int xPos; // x position
		int yPos; // y position
		int size; 
		int frame;
};

#endif
