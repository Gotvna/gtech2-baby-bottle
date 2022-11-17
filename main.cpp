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
	//Init SDL and throw an error if it fails
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

	//Init Bottle
	Bottle b;
	string openDate = b.getNow();
	//Get data from previous session
	b.translateFromTxt(b.readFromFile("takes.txt"));

	//Init Feeder
	inputField fdInput = inputField({ SCREEN_WIDTH / 2 - 150, 100, 300, 40 });
	fdInput.setData("Insert quantity");
	vector<Button> fdButtons;
	//Recreate buttons with correct color and text
	for (int i = 0; i < b.getTakes().size(); i++)
	{
		if (b.getTakes()[i].regurgitated)
		{
			fdButtons.push_back(Button({ 150, int(210 + i * 40), 150, 40 }, { 0, 0, 255, 255 }, { 0, 255, 0, 255 }, "Vomited"));
		}
		else
		{
			fdButtons.push_back(Button({ 150, int(210 + i * 40), 150, 40 }, { 255, 255, 0, 255 }, { 0, 255, 0, 255 }, "Vomit"));
		}
		if (b.getTakes()[i].taken)
		{
			fdButtons.push_back(Button({ 05, int(210 + i * 40), 130, 40 }, { 255, 0, 0, 255 }, { 255, 255, 255, 255 }, "Taken"));

		}
		else
		{
			fdButtons.push_back(Button({ 05, int(210 + i * 40), 130, 40 }, { 0, 0, 255, 255 }, { 255, 255, 255, 255 }, "Take"));
		}
	}
	
	//Shopping List
	ShoppingList sl = ShoppingList();
	//Get data from previous session
	sl.translateFromTxt(b.readFromFile("shopping_list.txt"));
	inputField slInput = inputField({ SCREEN_WIDTH / 2 - 100, 750, 200, 40 });
	slInput.setData("Insert Data");
	vector<Button> slButtons;
	//Create buttons for each item in the list from previous session
	for (int i = 0; i < sl.list.size(); i++)
	{
		slButtons.push_back(Button({ 05, int(825 + i * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "+"));
		slButtons.push_back(Button({ 50, int(825 + i * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "-"));
	}
	
	// Main loop
	bool running = true;
	SDL_Event event;
	while (running)
	{
		//Frame per second limiter
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
					//Feeder: interractions with input field
					if (fdInput.isClicked())
					{
						//Switch the input field to active
						if (fdInput.getData() == "Insert quantity")
							fdInput.setData("");
						string data = fdInput.takeFocus();
						if (data == "")
							fdInput.setData("Insert quantity");
						else
						{
							//Remove non numeric characters from input
							int quantity = 0;
							for (int i = 0; i < data.length(); i++)
							{
								if (data[i] >= '0' && data[i] <= '9')
									quantity = quantity * 10 + (data[i] - '0');
							}
							string date = b.getNow();
							date = date.substr(8, 2) + " " + date.substr(4, 3) + " " + date.substr(11, 5);
							//Create the new take
							b.NewTake(quantity, date);
							fdInput.setData("Insert quantity");
							//Create buttons for the new take
							fdButtons.push_back(Button({ 05, int(170 + b.getTakes().size() * 40), 130, 40 }, { 0, 0, 255, 255 }, { 255, 255, 255, 255 }, "Take"));
							fdButtons.push_back(Button({ 150, int(170 + b.getTakes().size() * 40), 150, 40 }, { 255, 255, 0, 255 }, { 0, 255, 0, 255 }, "Vomit"));
						}
					}
					//Feeder: interractions with buttons
					else for (int i = 0; i < fdButtons.size(); i++)
					{
						if (fdButtons[i].isClicked())
						{
							//Swap between "Take" and "Taken" states
							if (fdButtons[i].getText() == "Take")
							{
								fdButtons[i].setBgColor({ 255, 0, 0, 255 });
								fdButtons[i].setText("Taken");
								fdButtons[i].setRect({ fdButtons[i].getRect().x, fdButtons[i].getRect().y, 130, 40 });
								b.getTakes()[int(i / 2)].taken = true;
							}
							else if (fdButtons[i].getText() == "Taken")
							{
								fdButtons[i].setBgColor({ 0, 0, 255, 255 });
								fdButtons[i].setText("Take");
								fdButtons[i].setRect({ fdButtons[i].getRect().x, fdButtons[i].getRect().y, 130, 40 });
								b.getTakes()[int(i / 2)].taken = false;
							}
							//Swap between "Vomit" and "Vomited" states 
							else if (fdButtons[i].getText() == "Vomit")
							{
								fdButtons[i].setBgColor({ 0, 0, 255, 255 });
								fdButtons[i].setText("Vomited");
								fdButtons[i].setRect({ fdButtons[i].getRect().x, fdButtons[i].getRect().y, 150, 40 });
								b.getTakes()[int(i / 2)].regurgitated = true;
							}
							else if (fdButtons[i].getText() == "Vomited")
							{
								fdButtons[i].setBgColor({ 255, 255, 0, 255 });
								fdButtons[i].setText("Vomit");
								fdButtons[i].setRect({ fdButtons[i].getRect().x, fdButtons[i].getRect().y, 150, 40 });
								b.getTakes()[int(i / 2)].regurgitated = false;
							}
							break;
						}
					}
					//Shopping List: interraction with input field
					if (slInput.isClicked())
					{
						//Switch the input field to active
						if (slInput.getData() == "Insert item")
							slInput.setData("");
						string data = slInput.takeFocus();
						if (data == "")
							slInput.setData("Insert item");
						else
						{
							//Removes non alphanumerics characters from the input
							for (int i = 0; i < data.length(); i++)
							{
								if (!isalpha(data[i]))
								{
									data.erase(i, 1);
									i--;
								}
							}
							//Create new buttons
							slButtons.push_back(Button({ 05, int(825 + sl.list.size() * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "+"));
							slButtons.push_back(Button({ 50, int(825 + sl.list.size() * 40), 40, 40 }, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, "-"));
							//Add new item to the list
							sl.AddItem(Item({ data, 1 }));
							slInput.setData("Insert Data");
						}
					}
					//Shopping List: interraction with buttons
					else for (int i = 0; i < slButtons.size(); i++)
					{
						if (slButtons[i].isClicked())
						{
							//Add one to the quantity of the item
							if (slButtons[i].getText() == "+")
							{
								sl.list[int(i / 2)].quantity++;
							}
							//Remove one to the quantity, or delete the entry if the quantity is 0
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
				//Save data to file
				b.writeInFile("takes.txt", b.translateToTxt(), true);
				b.writeInFile("shopping_list.txt", sl.translateToTxt(), true);
			}
		}
		
		//Reset the window
		bw.Clear();

		//Draw text
		bw.drawText("Bottle scheduler", { SCREEN_WIDTH / 2 - 100, 10, 200, 50 }, { 0, 0, 0, 255 });
		bw.drawText(b.getNow(), { SCREEN_WIDTH / 2 - 100, 50, 200, 50 }, { 0, 0, 0, 255 });
		bw.drawTakes(b.getTakes());
		bw.drawText("Shopping List", { SCREEN_WIDTH / 2 - 100, 700, 200, 50 }, { 0, 0, 0, 255 });
		bw.drawShoppingList(sl.list);

		//Draw buttons
		for (int i = 0; i < slButtons.size(); i++) {
			bw.drawButton(slButtons[i]);
		};
		for (int i = 0; i < fdButtons.size(); i++) {
			bw.drawButton(fdButtons[i]);
		};
		
		//Draw input field
		bw.drawInput(slInput);
		bw.drawInput(fdInput);
		
		//Update
		bw.Update();
	}
	return 0;
}
