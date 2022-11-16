#include "SDL.h"
#include "window.h"
#include "const.h"
#include "date.h"
#include <iostream>
#include "shopping_list.h"
#include "inputField.h"
using namespace std;

Bottle_Window bw = Bottle_Window(SCREEN_WIDTH, SCREEN_HEIGHT);;


int main(int argc, char* argv[])
{
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
  
	//Text drawing test
	SDL_Color color = { 250, 250, 250 };
	SDL_Rect rect = {230, 30, 100, 100 };
	bw.drawText("Liste de courses", rect, color);

	//Input field test
	inputField input = inputField({ 0, 800, 100, 100 });
	input.setData("Test");

	//Shopping List
	ShoppingList sl = ShoppingList();
	sl.AddItem({ "Gruyere", 2 });
	sl.AddItem({ "Patate", 8 });
	bw.drawShoppingList(sl.GetList(), 0, 10);
	
	// Main loop

	bool running = true;
	int x;
	int y;
	SDL_Event event;
	SDL_Color color = { 250, 0, 0 };
	SDL_Rect rect = { 200, 200, 100, 100 };

	while (running)
	{

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					int mouseX, mouseY;
					SDL_GetMouseState(&mouseX, &mouseY);
					SDL_Rect rect = input.getRect();
					if (mouseX > rect.x && mouseX < rect.x + rect.w && mouseY > rect.y && mouseY < rect.y + rect.h)
					{
						input.takeFocus();
					}
					else if (x >= 900 && x <= 1000 && y >= 200 && y <= 300)
					{
						bw.drawText("Test", rect, color);
						break;
					}
				}
			}
	
		}
		
		//Drawing
		bw.drawInput(input);
		bw.Update();
		
	}
	return 0;
}
