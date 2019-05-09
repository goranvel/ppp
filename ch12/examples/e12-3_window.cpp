#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point t1 (500, 500);

	Simple_window win (t1, 600, 400, "Canvas");

	Graph_lib::Polygon poly;
	poly.add(Graph_lib::Point(300,400));
	poly.add(Graph_lib::Point(500,400));
	poly.add(Graph_lib::Point(500,500));

	poly.set_color (Graph_lib::Color::red);

	win.attach (poly);

	win.wait_for_button();

	return 0;
}
