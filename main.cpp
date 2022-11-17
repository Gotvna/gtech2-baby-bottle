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
	
	//Bottle
	Bottle b;
	string openDate = b.getNow();
	b.translateFromTxt(b.readFromFile("takes.txt"));

	//Feeder
	Bottle fd;
	inputField fdInput = inputField(SDL_Rect{ int(SCREEN_WIDTH / 2 - 100), int(SCREEN_HEIGHT / 2 - 100), 200, 50 }, SDL_Color{ 255, 255, 255, 255 }, SDL_Color{ 0, 0, 0, 255 }, "New Take");
	fdInput.setData("Insert quantity");
	vector<Button> fdButtons;
	
	//Shopping List
	ShoppingList sl = ShoppingList();
	sl.translateFromTxt(b.readFromFile("shopping_list.txt"));
	inputField slInput = inputField({ SCREEN_WIDTH / 2 - 100, 750, 200, 40 });
	slInput.setData("Insert Data");
	vector<Button> slButtons;
	
	// Main loop
	bool running = true;
	SDL_Event event;
	while (running)
	{
		SDL_Delay(1000 / 60);
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
							slButtons.push_back(Button({ 05, int(825 + sl.list.size() * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "+"));
							slButtons.push_back(Button({ 50, int(825 + sl.list.size() * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "-"));
							sl.AddItem(Item({ data, 1 }));
							slInput.setData("Insert Data");
						}
					}
					else for (int i = 0; i < slButtons.size(); i++)
					{
						if (slButtons[i].isClicked())
						{
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
					if (fdInput.isClicked()) 
					{

					}
					
				}
				b.writeInFile("takes.txt", b.translateToTxt(), true);
				b.writeInFile("shopping_list.txt", sl.translateToTxt(), true);
			}
		}
		
		bw.Clear();

		//Draw text
		bw.drawText("Bottle scheduler", { SCREEN_WIDTH / 2 - 100, 10, 200, 50 }, { 0, 0, 0, 255 });
		bw.drawText(b.getNow(), { SCREEN_WIDTH / 2 - 100, 50, 200, 50 }, { 0, 0, 0, 255 });
		bw.drawText("Shopping List", { SCREEN_WIDTH / 2 - 100, 700, 200, 50 }, { 0, 0, 0, 255 });
		bw.drawShoppingList(sl.list);

		//Draw buttons
		for (int i = 0; i < slButtons.size(); i++) {
			bw.drawButton(slButtons[i]);
		};
		
		//Draw input field
		bw.drawInput(slInput);
		
		//Update
		bw.Update();
	}
	return 0;
}
