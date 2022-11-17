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

std::string ShoppingList::translateToTxt()
{
	std::string data;
	for (int i = 0; i < list.size(); i++)
	{
		data += list[i].name + "|" + std::to_string(list[i].quantity) + "|";
	}
	return data;
}

void ShoppingList::translateFromTxt(std::string data)
{
	int i = 0;
	while (i < data.size())
	{
		Item item;
		string name;
		string quantity;
		//Transfer all chars before | to name
		while (data[i] != '|')
		{
			name += data[i];
			i++;
		}
		i++;
		//Transfer all chars before | to quantity
		while (data[i] != '|')
		{
			quantity += data[i];
			i++;
		}
		i++;
		item.name = name;
		item.quantity = stoi(quantity);
		list.push_back(item);
	}
}