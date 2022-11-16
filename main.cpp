#include "SDL.h"
#include "window.h"
#include "const.h"
#include "date.h"
#include <iostream>
#include "shopping_list.h"
using namespace std;


int main(int argc, char* argv[])
{
	Bottle_Window bw = Bottle_Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	switch (bw.Init())
	{
	case 1:
		cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError();
		return 1;
	case 2:
		cout << "Window could not be created! SDL_Error: %s\n" << SDL_GetError();
		return 1;
	default: break;
	}
  
	//Interactives elements creation
	Button b1 = Button(0, 0, 100, 100);
	b1.SetFont(bw.GetFont());
	b1.setText("Test");
  
	// Main loop
	bool running = true;
	while (running)
	{
		//Catching events
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		
		//Drawing
		bw.Update();
	}
	
	return 0;
}
