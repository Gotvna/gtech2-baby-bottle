#include <SDL.h>
#include <SDL_ttf.h>
#include "window.h"
#include "const.h"

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
	SetFont(TTF_OpenFont("/fonts/KeeponTruckin.ttf", 12));
	
	//Get window surface
	b_screenSurface = SDL_GetWindowSurface(b_window);
	SDL_FillRect(b_screenSurface, NULL, SDL_MapRGB(b_screenSurface->format, 100, 100, 100));

	SDL_Rect rect;
	rect.x = 220;
	rect.y = 100;
	rect.w = 200;
	rect.h = 80;
	SDL_FillRect(b_screenSurface, &rect, SDL_MapRGB(b_screenSurface->format, 255, 255, 255));
	
	SDL_Rect rect2;
	rect2.x = 220;
	rect2.y = 400;
	rect2.w = 200;
	rect2.h = 80;
	SDL_FillRect(b_screenSurface, &rect2, SDL_MapRGB(b_screenSurface->format, 255, 255, 255));

	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderDrawRect(renderer, &rect2);
	


	return 0;
}

void Bottle_Window::Update()
{
	//Update the surface
	SDL_UpdateWindowSurface(b_window);
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
