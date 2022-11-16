#include "inputField.h"
#include "window.h"

extern Bottle_Window bw;

inputField::inputField(SDL_Rect rect, SDL_Color bgColor, SDL_Color textColor, const char* data)
{
	this->rect = rect;
	this->bgColor = bgColor;
	this->textColor = textColor;
	this->data = data;
}

inputField::~inputField()
{
}

bool inputField::isClicked()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h)
		return true;
	return false;
}

string inputField::takeFocus()
{
	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_BACKSPACE:
					if (data.length() > 0)
					{
						data.pop_back();
					}
					break;
				case SDLK_RETURN:
					quit = true;
					break;
				default:
					data += e.key.keysym.sym;
					break;
				}
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					int mouseX, mouseY;
					SDL_GetMouseState(&mouseX, &mouseY);
					if (mouseX < rect.x || mouseX > rect.x + rect.w || mouseY < rect.y || mouseY > rect.y + rect.h)
					{
						quit = true;
					}
					break;
				}
			}
		}
		bw.drawInput(*this);
		bw.Update();
	}
	return data;
}
