#pragma once
#include <SDL.h>
#include "const.h"

class Button
{
public:
	Button(SDL_Rect rect, SDL_Color bgColor = {250, 250, 250}, SDL_Color textColor = {0, 0, 0}, const char* text = "Button");
	~Button();
	bool isClicked();
	void setRect() { this->rect = rect; }
	SDL_Rect getRect() { return rect; }
	void setBgColor(SDL_Color color) { this->bgColor = color; }
	SDL_Color getBgColor() { return bgColor; }
	void setTextColor(SDL_Color color) { this->textColor = color; }
	SDL_Color getTextColor() { return textColor; }
	void setText(const char* text) { this->text = text; }
	const char* getText() { return text; }

private:
	SDL_Rect rect;
	SDL_Color bgColor;
	const char* text;
	SDL_Color textColor;
};
