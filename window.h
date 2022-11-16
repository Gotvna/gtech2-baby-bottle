#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "shopping_list.h"
#include "inputField.h"
#include "const.h"
using namespace std;

class Bottle_Window
{
public:
	Bottle_Window(int window_width, int window_height);
	~Bottle_Window();
	int Init();
	void Update();
	void SetFont(TTF_Font* font) { this->font = font; }
	
	int GetWidth() { return b_window_width; }
	int GetHeight() { return b_window_height; }
	SDL_Window* GetWindow() { return b_window; }
	SDL_Surface* GetSurface() { return b_screenSurface; }
	TTF_Font *GetFont() { return font; }

	void drawText(string text, SDL_Rect rect, SDL_Color color);
	void drawInput(inputField input);
	void drawShoppingList(vector<Item> list, int page, int maxPerPage);
	
private:
	int b_window_width;
	int b_window_height;
	SDL_Window* b_window;
	SDL_Surface* b_screenSurface;
	TTF_Font* font = NULL;
	SDL_Renderer* renderer;

};
