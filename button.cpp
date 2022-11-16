#include "button.h"

Button::Button(SDL_Rect rect)
{
	this->rect = rect;
}

Button::~Button()
{
}

bool Button::isClicked(int x, int y)
{
	if (x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h)
		return true;
	return false;
}
