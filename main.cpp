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
	/*
	SDL_Color bleu = { 0, 0, 255, 255 };
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	*/

 


	//Interactives elements creation
	Button b1 = Button(0, 0, 100, 100);
	b1.SetFont(bw.GetFont());
	b1.setText("Test");
  
	//Text drawing test
	
	SDL_Color color = { 250, 250, 250 };
	SDL_Rect rect = {230, 30, 100, 100 };
	bw.drawText("Liste de courses", rect, color);

	//Shopping List
	ShoppingList sl = ShoppingList();
	sl.AddItem({ "Gruyere", 2 });
	sl.AddItem({ "Patate", 8 });
	bw.drawShoppingList(sl.GetList(), 0, 10);
	
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
