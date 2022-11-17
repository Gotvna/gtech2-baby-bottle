#pragma once
#pragma warning(disable : 4996)
#include <time.h>

int getHour()
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	return timeinfo->tm_hour;
}