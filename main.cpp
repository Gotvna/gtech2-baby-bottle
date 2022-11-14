#include "window.h"
#include "const.h"
#include "SDL.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	Bottle_Window bw = Bottle_Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	switch (bw.Init())
	{
	case 1:
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	case 2:
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	default: break;
	}
	
	// Main loop
	bool running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		bw.Update();
	}
	
	return 0;
}
