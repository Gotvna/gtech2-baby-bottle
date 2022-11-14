#pragma once
#include <SDL.h>
#include <stdio.h>

class Bottle {
	
public:
	Bottle();
	~Bottle();
	void take(int quantite_max, int quantite_min, int hour_take);
	void vomit(int quantite);
	void schedule_take(int next_take, int date);
	
private:
	int quantite_max;
	int quantite_min;
	int quantite;
	int next_take;
	int hour_take;
	int date;
	
};
