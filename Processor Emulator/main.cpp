#include "stdafx.h"
using namespace std;

// Screen resolution initializing
const int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
const int SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);

void gameClose(SDL_Window* window, vector<SDL_Surface*> surfaces)
{
	//Deallocate all surfaces
	for (int i = 0; i < surfaces.size(); i++)
	{
		SDL_FreeSurface(surfaces[i]);
	}
	// Destroy game window
	SDL_DestroyWindow(window);
	//Quit SDL
	SDL_Quit();
}

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
	SDL_Surface* screenSurface = NULL;
	// The image we will load and show on the screen
	SDL_Surface* HelloWorld = NULL;

	// Game window fullscreen initialization
	window = SDL_CreateWindow("Processor Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
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

	// Create hello world image
	HelloWorld = SDL_LoadBMP("Resources/Sprites/hello_world.bmp");
	if (HelloWorld == NULL)
	{
		cout << SDL_GetError() << endl;
		exit(-1);
	}
	// Main surface create
	SDL_BlitSurface(HelloWorld, NULL, screenSurface, NULL);
	// Update window surfaces
	SDL_UpdateWindowSurface(window);

	// Game window cycle
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

	gameClose(window, { screenSurface, HelloWorld });
	return 0;
}