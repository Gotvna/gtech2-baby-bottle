#include "window.h"
#include "const.h"
#include "date.h"
#include "reminder.cpp"
#include <iostream>
using namespace std;


int timer()
{
	using namespace date;
	using namespace std::chrono;
	std::cout << system_clock::now() << '\n';
	return 0;
}

int main(int argc, char* argv[])
{
	window_init(SCREEN_WIDTH, SCREEN_HEIGHT);
	timer();
	return 0;
}