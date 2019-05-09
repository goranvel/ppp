#include "../../Simple_window.h"
#include <stdexcept>
#include <cmath>

namespace Graph_lib {

	struct Regular_polygon : Shape {
		int width;
		int sides; // number of sides polygon has
		double radius;
		Graph_lib::Point center;
		vector<Point> points;

		Regular_polygon (Graph_lib::Point p, int w, int s) : center (p), width (w), sides (s) {
			if (w <= 0)
				std::cerr << "ERROR: Distance from center to a corner cannot be less than 1.\n";
			if (sides <= 2)
				std::cerr << "ERROR: Number of sides is incorect.\n";
			for (int i = 0; i < sides; ++i) 
				points.push_back (Point(center.x + width * std::cos (2 * i * std::acos(-1)/sides), 
														center.y + width * std::sin (2 * i * std::acos(-1)/sides)));
		}

		void draw_lines () const {
			if (fill_color().visibility()) {
				fl_color(fill_color().as_int());
				fl_begin_complex_polygon();
				for (int i = 0; i < sides; ++i) 
					fl_vertex (points[i].x, points[i].y);
				fl_end_complex_polygon();
			} 

			if (color().visibility()) {
				fl_color(color().as_int());

				for (int i = 0; i < sides; ++i)
					fl_line (points[i].x, points[i].y, 
									points[i + 1 == sides ? 0 : i + 1].x, points[i + 1 == sides ? 0 : i + 1].y);
			}
		}
	}; // class hex end

}
int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Hex");

	Graph_lib::Regular_polygon box (Graph_lib::Point (100, 100), 100, 8);
	box.set_fill_color(Graph_lib::Color::red);
	win.attach(box);

	win.wait_for_button();
	return 0;
}
