#pragma once
#include <SDL.h>
#include <stdio.h>

class Reminder {
public:
	Reminder();
	~Reminder();
	void interval_gap();
	void bottle_reminder();
	void bottle_take();
private:
	int hour;
	int minute;
	int interval;
	int bottle_count;
};
