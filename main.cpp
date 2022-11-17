#include <SDL.h>
#include <iostream>
#include <vector>
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
	
	
	//Shopping List
	ShoppingList sl = ShoppingList();
	inputField slInput = inputField({ 75, 550, 250, 40 });
	slInput.setData("Insert Data");
	vector<Button> slButtons;

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
					if (slInput.isClicked())
					{
						if (slInput.getData() == "Insert Data")
							slInput.setData("");
						string data = slInput.takeFocus();
						if (data == "")
							slInput.setData("Insert Data");
						else
						{ 
							sl.AddItem(Item({ data, 1 }));
							slButtons.push_back(Button({ 05, int(585 + sl.list.size() * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "+"));
							slButtons.push_back(Button({ 50, int(585 + sl.list.size() * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "-"));
							slInput.setData("Insert Data");
						}
					}
					else for (int i = 0; i < slButtons.size(); i++)
					{
						if (slButtons[i].isClicked())
						{
							cout << "Clicked button " << i << endl;
							if (slButtons[i].getText() == "+")
							{
								sl.list[int(i / 2)].quantity++;
							}
							else
							{
								sl.list[int(i / 2)].quantity--;
								if (sl.list[int(i / 2)].quantity == 0)
								{
									sl.list.erase(sl.list.begin() + int(i / 2));
									slButtons.erase(slButtons.begin() + i);
									slButtons.erase(slButtons.begin() + i - 1);
									for (int j = i - 1; j < slButtons.size(); j++)
									{
										slButtons[j].setRect({ slButtons[j].getRect().x, slButtons[j].getRect().y - 40, 40, 40 });
									}
								}
							}
							break;
						}
					}
				}
			}

			//Drawing
			bw.Clear();
			// Text
			bw.drawText("Bottle Scheduler", { 200, 20, 100, 100 }, { 0, 0, 0 });
			bw.drawText("Liste de courses", { 200, 500, 100, 100 }, { 0, 0, 0 });
			bw.drawShoppingList(sl.list, 0, 5);
			for (int i = 0; i < slButtons.size(); i++)
				bw.drawButton(slButtons[i]);
			bw.drawInput(slInput);
			bw.Update();

		}
	}
	return 0;
}
