#pragma warning(disable : 4996)
#include <SDL.h>
#include <iostream>
#include <vector>
#include "window.h"
#include "const.h"
#include "shopping_list.h"
#include "inputField.h"
#include "bottle.h"
#include "button.h"
#include <ctime>
#include <fstream>
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
	
	//Bottle buttons
	//Button newTakeButton = Button(int(SCREEN_WIDTH / 2 - 100), int(SCREEN_HEIGHT / 2 - 100), 200, 50, "New Take");

	Button hourTaken = Button({ 05, 120, 200, 50 }, { 255, 255, 255, 255 }, { 0, 0, 0, 255 }, "Save the hour");

	
	//Actual time function
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "Actual time is : " << dt << endl;

	fstream filestr;
	filestr.open("take.txt", fstream::out | fstream::app);
	filestr << dt << "actual time he take" << endl;
	filestr.close();
	cout << "Validate Hour" << endl;
	
	//Shopping List
	ShoppingList sl = ShoppingList();
	inputField slInput = inputField({ 75, 550, 250, 40 });
	slInput.setData("Insert Data");
	vector<Button> slButtons;
	
	bw.drawButton(Button({ 05, 120, 200, 50 }, { 255, 255, 255, 255 }, { 0, 0, 0, 255 }, "Save the hour"));
	
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
							slButtons.push_back(Button({ 05, int(625 + sl.list.size() * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "+"));
							slButtons.push_back(Button({ 50, int(625 + sl.list.size() * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "-"));
							sl.AddItem(Item({ data, 1 }));
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

					//Button à reparer (la function d'ecriture marche)

					
					if (hourTaken.getText() == "Validate Hour")
					{
						cout << "Validate Hour" << endl;
						time_t now = time(0);
						char* dt = ctime(&now);
						cout << "Actual time is : " << dt << endl;

						fstream filestr;
						filestr.open("take.txt", fstream::out | fstream::app);
						filestr << dt << "actual time he take" << endl;
						filestr.close();
					}
				}
			}

			bw.Clear();

			//Actual time function
			time_t now = time(0);
			char* dt = ctime(&now);
			cout << "Actual time is : " << dt << endl;

			//Draw text
			bw.drawText("Bottle scheduler", { SCREEN_WIDTH / 2 - 100, 10, 200, 50 }, { 0, 0, 0, 255 });
			bw.drawText(dt, { SCREEN_WIDTH / 2 - 300, 40, 200, 50 }, { 0, 0, 0, 255 });
			bw.drawText("Shopping List", { SCREEN_WIDTH / 2 - 100, 500, 200, 50 }, { 0, 0, 0, 255 });
			bw.drawShoppingList(sl.list, 0, 5);
			
			//Draw buttons
			for (int i = 0; i < slButtons.size(); i++) {
				bw.drawButton(slButtons[i]);
			};
			bw.drawButton(hourTaken);
			
			//Draw input field
			bw.drawInput(slInput);
			
			//Update
			bw.Update();
	
		}
	}
	return 0;
}
