#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

//Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize. SDL_Error: " << SDL_GetError() << endl;
	}
	else {
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window == NULL) {
			cout << "Window could not be created. SDL_Error: " << SDL_GetError() << endl;
		}
		else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			//Fill surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			//Update the surface
			SDL_UpdateWindowSurface(window);
		}

		SDL_Event windowEvent;
		while(true) {
			if(SDL_PollEvent(&windowEvent)) {
				//Waits until X is clicked to close window
				if(windowEvent.type == SDL_QUIT)
					break;
			}
		}
	}
	//Destroy window
	SDL_DestroyWindow(window);
	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
