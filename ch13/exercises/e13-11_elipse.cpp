#include "../../Simple_window.h"

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 800, 800, "Elipse on a graph");

	Graph_lib::Ellipse e (Graph_lib::Point(400, 400), 300, 200);
	win.attach (e);

	Graph_lib::Axis x (Graph_lib::Axis::x, Graph_lib::Point (50, 400), 700, 50, "X");
	win.attach (x);

	Graph_lib::Axis y (Graph_lib::Axis::y, Graph_lib::Point (400, 750), 700, 50, "Y");
	win.attach (y);

	Graph_lib::Mark f1 (Graph_lib::Point(400 + std::sqrt(300*300 - 200*200), 400), 'F');
	win.attach (f1);
	Graph_lib::Mark f2 (Graph_lib::Point(400 - std::sqrt(300*300 - 200*200), 400), 'F');
	win.attach (f2);

	int p = 400 + 200 * 300 / std::sqrt(300 * 300 + 200 * 200); 
	Graph_lib::Mark point (Graph_lib::Point(p, p), 'P');
	win.attach (point);

	Graph_lib::Line l1 (Graph_lib::Point(400 + std::sqrt(300*300 - 200*200), 400), Graph_lib::Point(p, p));
	win.attach (l1);
	Graph_lib::Line l2 (Graph_lib::Point(400 - std::sqrt(300*300 - 200*200), 400), Graph_lib::Point(p, p));
	win.attach (l2);

	win.wait_for_button();

	return 0;
}
