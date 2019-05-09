#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point t1 (2500, 500);

   Simple_window win (t1, 600, 400, "Canvas");

	Graph_lib::Polygon poly;
	poly.add (Graph_lib::Point (300, 200));
	poly.add (Graph_lib::Point (300, 100));
	poly.add (Graph_lib::Point (400, 100));
	poly.add (Graph_lib::Point (400, 200));
	win.attach (poly);
	
	Graph_lib::Rectangle rect (Graph_lib::Point (200, 200), 100, 50);
	win.attach(rect);

   win.set_label ("My ...");
	win.wait_for_button();

	return 0;
}
