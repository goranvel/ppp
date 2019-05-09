#include "../../Simple_window.h"

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Circle it");

	int radius = 200;
	Graph_lib::Point center (250, 250);

	Graph_lib::Circle c (center, radius);
	win.attach (c); 
	Graph_lib::Point p (center.x + radius, center.y);
	Graph_lib::Mark point (p, '.');
	win.attach (point);
	win.wait_for_button ();


	for (int i = 0; i < 10; ++i) {
		double xDif = radius * std::cos (((i + 1) % 10) * 2 * std::acos (-1) / 10) -
							radius * std::cos (i  * 2 * std::acos (-1) / 10);
		double yDif = radius * std::sin (((i + 1) % 10) * 2 * std::acos (-1) / 10) -
							radius * std::sin (i  * 2 * std::acos (-1) / 10);
		point.move (xDif, yDif);

		win.wait_for_button();
	}

	return 0;
}
