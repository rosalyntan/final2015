#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Key press surfaces constants
enum KeyPressSurfaces {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia();
//Frees media and shuts down SDL
void close();
//Loads individual image
SDL_Surface* loadSurface(string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

int main(int argc, char* argv[]) {
	//Start up SDL and create window
	if(!init()) {
		cout << "Failed to initialize." << endl;
	}
	else {
		//Load media
		if(!loadMedia()) {
			cout << "Failed to load media." << endl;
		}
		else {
			//Main loop flag
			bool quit = false;
			//Event handler
			SDL_Event e;
			//Set default current surface
			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
			//While application is running
			while(!quit) {
				//Handle events on queue
				while(SDL_PollEvent(&e)) {
					//User requests quit
					if(e.type == SDL_QUIT) {
						quit = true;
					}
					//User presses a key
					else if(e.type == SDL_KEYDOWN) {
						//Select surfaces based on key press
						switch(e.key.keysym.sym) {
							case SDLK_UP:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
								break;
							case SDLK_DOWN:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
								break;
							case SDLK_LEFT:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
								break;
							case SDLK_RIGHT:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
								break;
							default:
								gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
								break;
						}
					}
				}
				//Apply the image
				SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
				//Update the surface
				SDL_UpdateWindowSurface(gWindow);	
			}
		}
	}
	//Free resources and close SDL
	close();

	return 0;
}

bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize. SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else {
		//Create window
		gWindow = SDL_CreateWindow("SDL Image Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL) {
			cout << "Window could not be created. SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else {
			// Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load default surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("press.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL) {
		cout << "Failed to load default image." << endl;
		success = false;
	}

	//Load up surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("up.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL) {
		cout << "Failed to load up image." << endl;
		success = false;
	}

	//Load down surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("down.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL) {
		cout << "Failed to load down image." << endl;
		success = false;
	}

	//Load left surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("left.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL) {
		cout << "Failed to load left image." << endl;
		success = false;
	}

	//Load right surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("right.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL) {
		cout << "Failed to load right image." << endl;
		success = false;
	}
	return success;
}

void close() {
	//Deallocate surface
	SDL_FreeSurface(gCurrentSurface);
	gCurrentSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

SDL_Surface* loadSurface(string path) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if(loadedSurface == NULL) {
		cout << "Unable to load image " << path.c_str() << ". SDL Error: " << SDL_GetError() << endl;
	}
	else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if(optimizedSurface == NULL) {
			cout << "Unable to optimize image " << path.c_str() << ". SDL Error: " << SDL_GetError() << endl;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}	
	return optimizedSurface;
}
