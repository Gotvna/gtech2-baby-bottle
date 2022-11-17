#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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

vector<Item> ShoppingList::GetList()
{
	return list;
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
