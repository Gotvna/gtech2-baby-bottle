//Using SDL and standard IO
#include <SDL.h>
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

	//Quit SDL subsystems
	SDL_Quit();
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
	
	//Get window surface
	b_screenSurface = SDL_GetWindowSurface(b_window);
}

void Bottle_Window::Update()
{
	//Update the surface
	SDL_UpdateWindowSurface(b_window);
}

Button::Button(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	rect = { x, y, w, h };
}