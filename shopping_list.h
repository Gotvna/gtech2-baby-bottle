#pragma once
#include <vector>
#include <string>
#include <SDL.h>
#include <iostream>

using namespace std;

struct Item
{
	string name;
	int quantity;
};

class ShoppingList
{
public:
	ShoppingList();
	~ShoppingList();
	void AddItem(Item i);
	vector<Item> list;
};
