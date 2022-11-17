#include "shopping_list.h"

using namespace std;

SDL_Renderer* renderer = nullptr;

Item InitProduit(string n, int q)
{
	Item i;
	i.name = n;
	i.quantity = q;
	return i;
}

ShoppingList::ShoppingList()
{
}

ShoppingList::~ShoppingList()
{
}	

void ShoppingList::AddItem(Item i)
{
	list.push_back(i);
}