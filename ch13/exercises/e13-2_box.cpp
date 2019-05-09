#include "../../Simple_window.h"
#include <stdexcept>

namespace Graph_lib {

struct Box : Shape {
	int width, height;
	double radius;
	Graph_lib::Point point;

	Box (Graph_lib::Point p, int w, int h, double rr) :
			point (p), width (w), height (w), radius (rr) {
		if (w <= 0 || height <= 0 || radius <= 0)
			throw std::runtime_error ("Width, height and radius have to be positive numbers");
	}

	void draw_lines () const {
		if (fill_color().visibility()) {
			fl_color (fill_color().as_int()); 

			fl_rectf	(point.x + radius / 2, point.y, width - radius, height);
			fl_rectf	(point.x, point.y + radius / 2, radius / 2, height - radius);
			fl_rectf	(point.x + width - radius / 2, point.y + radius / 2, radius / 2, height - radius);

			fl_pie	(point.x, point.y, radius, radius, 90, 180);
			fl_pie	(point.x + width - radius, point.y, radius, radius, 0, 90);
			fl_pie	(point.x, point.y + height - radius, radius, radius, 180, 270);
			fl_pie	(point.x + width - radius, point.y + height - radius, radius, radius, 270, 360);
		}

		if (color().visibility()) {
			fl_color (color().as_int());
			fl_line	(point.x + radius / 2, point.y, point.x - radius / 2 + width, point.y);
			fl_line	(point.x + radius / 2, point.y + height, point.x - radius / 2 + width, point.y + height);
			fl_line	(point.x, point.y + radius / 2, point.x, point.y - radius / 2 + height);
			fl_line	(point.x + width, point.y + radius / 2, point.x + width, point.y - radius /2 + height);

			fl_arc	(point.x, point.y, radius, radius, 90, 180);
			fl_arc	(point.x - radius + width, point.y, radius, radius, 0, 90);
			fl_arc	(point.x, point.y - radius + height, radius, radius, 180, 270);
			fl_arc	(point.x - radius + width, point.y - radius + height, radius, radius, 270, 360);
		}
	} 
};

}
int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Arch");

	Graph_lib::Box box (Graph_lib::Point (100, 100), 100, 100, 50);
//	box.set_fill_color(Graph_lib::Color::red);
	win.attach(box);

	win.wait_for_button();
	return 0;
}
