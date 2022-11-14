#pragma once
#include <SDL.h>

class Bottle_Window
{
public:
	Bottle_Window(int window_width, int window_height);
	~Bottle_Window();
	int Init();
	void Update();
	
	int GetWidth() { return b_window_width; }
	int GetHeight() { return b_window_height; }
	SDL_Window* GetWindow() { return b_window; }
	SDL_Surface* GetSurface() { return b_screenSurface; }
	
private:
	int b_window_width;
	int b_window_height;
	SDL_Window* b_window;
	SDL_Surface* b_screenSurface;
};

class Button
{
public:
	Button(int x, int y, int w, int h);
	SDL_Rect GetRect() { return rect; }

private:
	int x, y, w, h;
	SDL_Rect rect;
};