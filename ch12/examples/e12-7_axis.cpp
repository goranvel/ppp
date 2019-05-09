#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point t1 (500, 500);

	Simple_window win (t1, 600, 400, "Canvas");

	Graph_lib::Axis xAxis (Graph_lib::Axis::x, Graph_lib::Point(20, 300), 280, 10, "x");

	win.attach (xAxis);

	Graph_lib::Axis yAxis (Graph_lib::Axis::y, Graph_lib::Point(20, 300), 200, 10, "y");
	yAxis.set_color(Graph_lib::Color::cyan);
	yAxis.label.set_color(Graph_lib::Color::dark_red);

	win.attach (yAxis);
	win.set_label ("My axis");
	win.wait_for_button();

	return 0;
}
