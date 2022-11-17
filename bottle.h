#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Take {
	int id;
	int quantity;
	bool taken;
	bool regurgitated;
};
	
class Bottle {
private:
	std::vector<Take> takes;

public:
	Bottle();
	~Bottle();
	void NewTake(int quantity, bool taken = false);
	vector<Take> getTakes();
	void TakeTaken(int id);
	void TakeRegurgitated(int id);
	//void writeTakes(const char* file = "list.takes");
	//void readTakes(const char* file = "list.takes");
};