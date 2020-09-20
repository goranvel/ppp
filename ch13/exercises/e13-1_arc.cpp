#include "../../Simple_window.h"
#include "../../Graph.h"

namespace Graph_lib {

struct Arc : Shape {
	double alpha, betta, radius;
	Graph_lib::Point point;

	Arc (Graph_lib::Point p, double rr, double a, int b) :
			point (p), radius (rr), alpha (a), betta(b) {}

	void draw_lines () const {
		if (color().visibility())
			fl_arc(point.x, point.y, radius, radius, alpha, betta);
	} 
};

}
int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Arch");

	Graph_lib::Arc arc (Graph_lib::Point (100, 100), 50, 0, 90);
	win.attach(arc);

	win.wait_for_button();
	return 0;
}
