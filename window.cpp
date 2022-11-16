#include <SDL.h>
#include <SDL_ttf.h>
#include "window.h"
#include "inputField.h"
#include "const.h"
using namespace std;

Bottle_Window::Bottle_Window(int window_width, int window_height)
{
	b_window_width = window_width;
	b_window_height = window_height;
	b_window = NULL;
	b_screenSurface = NULL;
}

Bottle_Window::~Bottle_Window() {
	//Destroy window
	SDL_DestroyWindow(b_window);
	SDL_Quit();

	TTF_CloseFont(font);
	TTF_Quit();
}
	
int Bottle_Window::Init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1;

	//Create window
	b_window = SDL_CreateWindow("Bottle Scheduler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, b_window_width, b_window_height, SDL_WINDOW_SHOWN);
	if (b_window == NULL)
		return 2;

	//Initialize SDL_ttf (text rendering)
	if (TTF_Init() == -1)
		return 3;
	SetFont(TTF_OpenFont("fonts/Reglisse.otf", 30));

	//Get window surface
	b_screenSurface = SDL_GetWindowSurface(b_window);
	SDL_FillRect(b_screenSurface, NULL, SDL_MapRGB(b_screenSurface->format, 100, 100, 100));
	return 0;
}

void Bottle_Window::Update()
{
	SDL_UpdateWindowSurface(b_window);
}

void Bottle_Window::drawText(string text, SDL_Rect rect, SDL_Color color)
{
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_BlitSurface(textSurface, NULL, b_screenSurface, &rect);
	SDL_FreeSurface(textSurface);
}

void Bottle_Window::drawInput(inputField input)
{
	SDL_Rect rect = input.getRect();
	SDL_FillRect(b_screenSurface, &rect, SDL_MapRGB(b_screenSurface->format, 255, 255, 255));
	drawText(input.getData(), rect, {0, 0, 0});
}

void Bottle_Window::drawShoppingList(vector<Item> list, int page, int maxPerPage){
	SDL_Rect rect;
	
	int start = page * maxPerPage;
	size_t end;
	if (start + maxPerPage > list.size())
		end = list.size();
	else 
		end = start + maxPerPage;
	for (int i = start; i < end; i++)
	{
		char buffer[30];
		_itoa_s(list[i].quantity, buffer, 30, 10);
		
		rect.x = 20;
		rect.y = 100 + i * 30;
		rect.w = 200;
		rect.h = 15;
		SDL_FillRect(b_screenSurface, &rect, SDL_MapRGB(b_screenSurface->format, 100, 100, 100));
		drawText(list[i].name + " : " + buffer, rect, {0, 0, 0});
	}
}

void Bottle_Window::changePage() {
	SDL_Rect rect;

	rect.x = 200;
	rect.y = 40;
	rect.w = 200;
	rect.h = 20;
	SDL_FillRect(b_screenSurface, &rect, SDL_MapRGB(b_screenSurface->format, 255, 255, 255));
	drawText("bonjour", rect, {0, 0, 0});
}
//Button
Button::Button(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Button::~Button()
{
}
