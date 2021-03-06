//Kim's 2.5D animation tutorial from http://www.sdltutorials.com/sdl-tutorial-basics
//Part 1 - Basics

#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL2/SDL.h>

class CApp {
	private:
		bool Running;
	public:
		CApp();
		int OnExecute();
		bool OnInit();
		void OnEvent(SDL_Event* Event);
		void OnLoop();
		void OnRender();
		void OnCleanup();
};

#endif
