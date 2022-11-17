#include <SDL.h>
#include <iostream>
#include "window.h"
#include "const.h"
#include "shopping_list.h"
#include "inputField.h"
#include "bottle.h"
#include "button.h"
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
	Button b1 = Button({ 0, 0, 100, 100 });
	b1.setText("Test");

	//Title text
	SDL_Color color1 = { 0, 0, 0 };
	SDL_Rect rect1 = { 200, 20, 100, 100 };
	bw.drawText("Bottle Scheduler", rect1, color1);
	
	//Title max quantity
	SDL_Color color2 = { 255, 255, 255 };
	SDL_Rect rect2 = { 50, 100, 100, 100 };
	bw.drawText("Max quantity :", rect2, color2);
	
	//Input field max quantity
	inputField input_max = inputField({ 75, 150, 250, 40 });
	input_max.setData("Insert Data");

	//Title current quantity
	SDL_Color color3 = { 255, 255, 255 };
	SDL_Rect rect3 = { 50, 200, 100, 100 };
	bw.drawText("Current quantity :", rect3, color3);
	
	//Input field current quantity
	inputField input_current = inputField({ 75, 250, 250, 40 });
	input_current.setData("Insert Data");
	
	//Title min quantity
	SDL_Color color4 = { 255, 255, 255 };
	SDL_Rect rect4 = { 50, 300, 100, 100 };
	bw.drawText("Min quantity :", rect4, color4);
	
	//Input field min quantity
	inputField input_min = inputField({ 75, 350, 250, 40 });
	input_min.setData("Insert Data");
	
	//Text drawing test
	SDL_Color color = { 0, 0, 0 };
	SDL_Rect rect = {200, 500, 100, 100 };
	bw.drawText("Liste de courses", rect, color);
	
	//Input field
	inputField input = inputField({ 75, 550, 250, 40 });
	input.setData("Insert Data");
	

	//Shopping List
	ShoppingList sl = ShoppingList();
	bw.drawShoppingList(sl.GetList(), 0, 5);

	// Main loop

	bool running = true;
	SDL_Event event;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					SDL_Rect rect;

					rect = input.getRect();
					if (input.isClicked())
					{
						cout << "Input field clicked" << endl;
						if (input.getData() == "Insert Data")
							input.setData("");
						string data = input.takeFocus();
						if (data == "")
							input.setData("Insert Data");
						else
							{ 
							sl.AddItem(Item({ data, 1 }));
							bw.drawShoppingList(sl.GetList(), 0, 5);
							input.setData("Insert Data");
						}
					}
					
					rect = b1.getRect();
					if (b1.isClicked())
					{
						cout << "Button clicked" << endl;
					}
				}
			}

			//Drawing
			bw.drawInput(input);
			bw.Update();

		}
	}
	return 0;
}
