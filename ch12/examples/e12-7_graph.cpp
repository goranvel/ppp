#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point t1 (2500, 500);

	Simple_window win (t1, 600, 400, "Canvas");

	Graph_lib::Axis xAxis (Graph_lib::Axis::x, Graph_lib::Point(20, 300), 200, 10, "x");
	win.attach (xAxis);

	Graph_lib::Axis yAxis (Graph_lib::Axis::y, Graph_lib::Point(20, 300), 280, 10, "y");
	win.attach (yAxis);

	Graph_lib::Function sine (std::sin, 0, 100, Graph_lib::Point(20, 150), 1000, 50, 50);
	sine.set_color (Graph_lib::Color::blue);
	win.attach (sine);

	win.set_label ("My graph");
	win.wait_for_button();

	return 0;
}
