#include "../../Simple_window.h"
#include "../../Graph.h"

int main (void) {
	Graph_lib::Point t1 (2500, 500);

	Simple_window win (t1, 600, 400, "Canvas");


	Graph_lib::Rectangle rect (Graph_lib::Point (100, 100), 200, 300);
	win.attach(rect);

	Graph_lib::Text text (Graph_lib::Point (200,300), "Howdy!");
	win.attach (text); 
	win.set_label ("My Rectangles");
	win.wait_for_button();

	return 0;
}
