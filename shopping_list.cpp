#include <iostream>
#include <vector>
#include <string>
#include "shopping_list.h"
#include <SDL.h>

using namespace std;

SDL_Renderer* renderer = nullptr;

Item InitProduit(string n, int q)
{
	Item i;
	i.name = n;
	i.quantity = q;
	return i;
}

//void shows(Items P) {
//	cout << Items.name << " " << Items.quantity << endl;
//}

ShoppingList::ShoppingList()
{
}

ShoppingList::~ShoppingList()
{
}	

void ShoppingList::ShowList()
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i].name << " " << list[i].quantity << endl;
	}
}	

void ShoppingList::AddItem(Item i)
{
	list.push_back(i);
}

void ShoppingList::RemoveItem(Item i)
{
	for (int j = 0; j < list.size(); j++)
	{
		if (list[j].name == i.name)
		{
			list.erase(list.begin() + j);
		}
	}
}





void ShoppingList::RemoveItem(int index)
{
	list.erase(list.begin() + index);
}

void ShoppingList::RemoveItem(string name)
{
	for (int j = 0; j < list.size(); j++)
	{
		if (list[j].name == name)
		{
			list.erase(list.begin() + j);
		}
	}
}






//Console mode functions (DO NOT USE ANYMORE)
/*void DisplayItem(const Item i)
{
	cout << "name :" << i.name << " ; quantity : " << i.quantity << endl;
}

void ShowList(const vector<Item>& L)
{
	for (Item i : L)
	{
		DisplayItem(i);
	}
}

void InitListCourses(vector<Item>& L)
{
	string n; int q;
	char r = 'y';
	do
	{
		cout << "item name" << endl;
		cin >> n;
		cout << "quantity " << endl;
		cin >> q;
		L.resize(L.size() + 1);
		L[L.size() - 1] = InitProduit(n, q);
		cout << "" << endl;
		ShowList(L);
		cout << "" << endl;

		cout << "Anything else? (y/n)";
		cin >> r;
	} while (r == 'y');
}*/
