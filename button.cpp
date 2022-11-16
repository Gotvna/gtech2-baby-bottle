#include "button.h"

Button::Button(SDL_Rect rect, SDL_Color bgColor, SDL_Color textColor, const char* text)
{
	this->rect = rect;
	this->bgColor = bgColor;
	this->textColor = textColor;
	this->text = text;
}

Button::~Button()
{
}

bool Button::isClicked()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h)
		return true;
	return false;
}
