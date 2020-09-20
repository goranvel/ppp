#include "../../Simple_window.h"

int main (void) {
	Simple_window win (Graph_lib::Point(1920, 0), 500, 500, "Copy");

	Graph_lib::Circle c (Graph_lib::Point(100, 100), 75);
/*
	Graph_lib::Circle c1 = c;
	win.attach (c);
*/
	Graph_lib::Circle c2 (c);
	win.wait_for_button();
	return 0;
}
