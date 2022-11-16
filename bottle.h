#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>


class Bottle {
public:
	Bottle();
	~Bottle();
	void NewTake(int quantity, int hour, int date, bool taken = false);
	Take GetTake(int id);
	void TakeTaken(int id);
	void TakeRegurgitated(int id);
	//void writeTakes(const char* file = "list.takes");
	//void readTakes(const char* file = "list.takes");

private:
	struct Take {
		int id;
		int quantity;
		int hour;
		int date;
		bool taken;
		bool regurgitated;
	};

	std::vector<Take> takes;
};