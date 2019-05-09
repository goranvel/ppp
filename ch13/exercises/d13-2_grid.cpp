#include "../../Simple_window.h"
#include <vector>

int main (void) {
	Graph_lib::Point p (1900, 0);

	Simple_window win (p, 1000, 800, "CH 13 Drill 1");

	// adds grid
	Graph_lib::Lines lines;
	for (int i = 0, points = 0; i < 8; ++i, points += 100) {
		lines.add(Graph_lib::Point (points, 0), Graph_lib::Point (points, 800));
		lines.add(Graph_lib::Point (0, points), Graph_lib::Point (800, points));
	}
	win.attach (lines);

	win.wait_for_button();
	return 0;
}
