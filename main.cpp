#include "window.h"
#include "const.h"
#include "liste_course.h"



int main(int argc, char* argv[])
{
	vector<Produit> newCourse;
	InitListCourses(newCourse);


	window_init(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	
	return 0;
}