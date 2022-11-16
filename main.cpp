#include "window.h"
#include "const.h"
#include "date.h"
#include "reminder.cpp"
#include "shopping_list.h"
#include "SDL.h"
#include <stdio.h>
#include <iostream>
using namespace std;


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
  
	//Interactives elements creation
	Button b1 = Button(0, 0, 100, 100);
	b1.SetFont(bw.GetFont());
	b1.setText("Test");
  
	//Text drawing test
	SDL_Color color = { 250, 0, 0 };
	SDL_Rect rect = { 0, 0, 100, 100 };

	//Shopping List
	ShoppingList sl = ShoppingList();
	sl.AddItem({ "Gruyère", 2 });
	sl.AddItem({ "Patate", 8 });
	bw.drawShoppingList(sl.GetList(), 0, 10);
	
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
