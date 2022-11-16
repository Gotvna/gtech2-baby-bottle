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

	//Text drawing test
	SDL_Color color = { 250, 250, 250 };
	SDL_Rect rect = {230, 500, 100, 100 };
	bw.drawText("Liste de courses", rect, color);

	//Input field
	inputField input = inputField({ 0, 550, 250, 40 });
	input.setData("Insert Data");
	
	//input field with quantity
	vector<Item> list;
	int i;
	char buffer[30];
	_itoa_s(list[i].quantity, buffer, 30, 10);
	inputField input2 = inputField({ 0, 600, 250, 40 });
	input2.setData("Insert Data");
	

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
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					SDL_Rect rect;
					int mouseX, mouseY;
					SDL_GetMouseState(&mouseX, &mouseY);
					cout << "Mouse clicked at: " << mouseX << ", " << mouseY << endl;

					rect = input.getRect();
					if (mouseX > rect.x && mouseX < rect.x + rect.w && mouseY > rect.y && mouseY < rect.y + rect.h)
					{
						input.setData("");
						input.takeFocus();
						if (input.getData() != "" && SDLK_KP_ENTER)
						{
							sl.AddItem({ input.getData(), input2.getData()});
							bw.drawShoppingList(sl.GetList(), 0, 10);
							input.setData("Insert Data");
						}
					}
					
					//Check collision with button
					rect = b1.getRect();
					if (mouseX > rect.x && mouseX < rect.x + rect.w && mouseY > rect.y && mouseY < rect.y + rect.h)
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
