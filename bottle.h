#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Take {
		int id;
		int quantity;
		int hour;
		int date;
		bool taken;
		bool regurgitated;
};

class Bottle {

public:
	Bottle();
	~Bottle();
	void NewTake(int quantity, int hour, int date, bool taken = false);
	void TakeTaken(int id);
	void TakeRegurgitated(int id);
	std::vector<Take>& getTakes() { return takes; };
	Take getTake(int id) { return takes[id]; };
	//void writeTakes(const char* file = "list.takes");
	//void readTakes(const char* file = "list.takes");

private:
	std::vector<Take> takes;
};