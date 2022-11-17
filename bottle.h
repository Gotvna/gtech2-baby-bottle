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
	void writeInFile(std::string fileName, std::string data, bool rewrite = false);
	std::string readFromFile(std::string fileName);
	std::string getNow();
	std::string translateToTxt();
	void translateFromTxt(std::string data);
	
private:
	std::vector<Take> takes;
};