#include "stdafx.h"
using namespace std;

// Game window constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char** argv)
{
	// If SDL not full working throw error
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << SDL_GetError() << endl;
		exit(-1);
	}

	// Game window creation
	SDL_Window* window = NULL;
	// Surface in the game window creation
	SDL_Surface * screenSurface = NULL;

	// Game window initialization
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	// If game window not initialize throw error
	if (window == NULL)
	{
		cout << SDL_GetError() << endl;
		exit(-1);
	}
	// Surface initialization
	screenSurface = SDL_GetWindowSurface(window);
	// Surface fill
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	// Surface update
	SDL_UpdateWindowSurface(window);

	// Game window cycle
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

	// Destroy game window
	SDL_DestroyWindow(window);
	//Quit SDL
	SDL_Quit();

	return 0;
}