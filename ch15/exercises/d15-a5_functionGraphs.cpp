#include "../../Simple_window.h"

int main (void) {
	Simple_window win (Graph_lib::Point(1920, 0), 1920, 1080, "Function Graphs");

	// Axis
	Graph_lib::Axis x (Graph_lib::Axis::x, Graph_lib::Point(100,300), 400, 400/20, "1 == 20 pixels");
	x.set_color (Graph_lib::Color::red);
	win.attach(x);

	Graph_lib::Axis y (Graph_lib::Axis::y, Graph_lib::Point(300, 500), 400, 400/20, "1 == 20 pixels");
	y.set_color (Graph_lib::Color::red);
	win.attach(y);


	win.wait_for_button();
	
	return 0;
}
