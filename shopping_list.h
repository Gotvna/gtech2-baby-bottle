#pragma once
#include <vector>
#include <string>

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
	vector<Item> GetList();
	void AddItem(Item i);
	void RemoveItem(Item i);
	void RemoveItem(int index);
	void RemoveItem(string name);

private:
	vector<Item> list;
};



//Console mode functions:
//void DisplayItem(const Item i);
//void ShowList(const vector<Item>& L);
//void InitListCourses(vector<Item>& L);