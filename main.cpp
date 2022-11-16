#include "window.h"
#include "const.h"
#include "date.h"
#include "reminder.cpp"
#include <iostream>
using namespace std;
#include "liste_course.h"

#include "SDL.h"
#include <stdio.h>
#include "liste_course.h"



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
	/*
	SDL_Color bleu = { 0, 0, 255, 255 };
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	*/

 


	//Interactives elements creation
	Button b1 = Button(0, 0, 100, 100);
	b1.SetFont(bw.GetFont());
	b1.setText("Test");
  
	// Main loop

	bool running = true;
	SDL_Event event;

	while (running)
	{

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			else if (event.type == SDL_BUTTON_LEFT)
			{

			}
		}
		
		//Drawing
		bw.Update();
	}
	return 0;
}
