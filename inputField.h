#pragma once
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;

class inputField
{
public:
	inputField(SDL_Rect rect);
	~inputField();
	string takeFocus();
	SDL_Rect getRect() { return rect; }
	void setRect(SDL_Rect rect) { this->rect = rect; }
	string getData() { return data; }
	void setData(string data) { this->data = data; }
	
private:
	SDL_Rect rect;
	string data;
};

