#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include "const.h"

class inputField
{
public:
	inputField(SDL_Rect rect, SDL_Color bgColor = {250, 250, 250}, SDL_Color textColor = {0, 0, 0}, const char* data = ". . .");
	~inputField();
	bool isClicked();
	string takeFocus();
	void setRect() { this->rect = rect; }
	SDL_Rect getRect() { return rect; }
	void setBgColor(SDL_Color color) { this->bgColor = color; }
	SDL_Color getBgColor() { return bgColor; }
	void setTextColor(SDL_Color color) { this->textColor = color; }
	SDL_Color getTextColor() { return textColor; }
	void setData(const char* data) { this->data = data; }
	string getData() { return data; }

private:
	SDL_Rect rect;
	SDL_Color bgColor;
	string data;
	SDL_Color textColor;
};

