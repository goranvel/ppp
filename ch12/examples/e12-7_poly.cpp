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

	Graph_lib::Polygon poly;
	poly.add (Graph_lib::Point (300, 200));
	poly.add (Graph_lib::Point (350, 100));
	poly.add (Graph_lib::Point (400, 200));
	poly.set_color (Graph_lib::Color::red);
	poly.set_style(Graph_lib::Line_style::dash);
	win.attach (poly);

	win.set_label ("My polygon");
	win.wait_for_button();

	return 0;
}
