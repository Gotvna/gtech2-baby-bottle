#pragma once
#include <SDL.h>

class Button
{
public:
	Button(SDL_Rect rect);
	~Button();
	bool isClicked(int x, int y);
	void setRect() { this->rect = rect; }
	SDL_Rect getRect() { return rect; }
	void setText(const char* text) { this->text = text; }
	const char* getText() { return text; }

private:
	SDL_Rect rect;
	const char* text;
};
