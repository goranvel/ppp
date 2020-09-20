#include "../../Simple_window.h"
#include <stdexcept>
#include <cmath>

namespace Graph_lib {
	struct Octagon : public Closed_polyline {
		int width;
		double radius;
		Graph_lib::Point center;

		Octagon (Graph_lib::Point p, int w) : center (p), width (w) {
			for (int i = 0; i <= 8; ++i) {
/*	fl_line (center.x + width * std::cos (i * std::acos(-1)/3), 
											center.y + width * std::sin (i * std::acos(-1)/3),
									center.x + width * std::cos ((i + 1)  * std::acos(-1)/3), 
											center.y + width * std::sin ((i + 1) * std::acos(-1)/3));
*/			
				add (Point (center.x + width * std::cos (i * std::acos(-1)/4), 
											center.y + width * std::sin (i * std::acos(-1)/4)));/*
				add (Point (center.x + width * std::cos ((i + 1)  * std::acos(-1)/3), 
											center.y + width * std::sin ((i + 1) * std::acos(-1)/3))); */

			}
		}

		void draw_lines () const {
			if (fill_color().visibility()) {
				fl_color(fill_color().as_int());
				fl_begin_complex_polygon();
				for (int i = 0; i < 8; ++i) {
					fl_vertex (point(i).x, point(i).y);
				}
				fl_end_complex_polygon();
			} 

		/*	if (color().visibility()) {
				fl_color(color().as_int());

				for (int i = 0; i < 6; ++i) {
						fl_line (center.x + width * std::cos (i * std::acos(-1)/3), 
											center.y + width * std::sin (i * std::acos(-1)/3),
									center.x + width * std::cos ((i + 1)  * std::acos(-1)/3), 
											center.y + width * std::sin ((i + 1) * std::acos(-1)/3));
				}
				draw_lines ();

			} */


		}
	}; // class hex end

}
int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Hex");

	Graph_lib::Octagon box (Graph_lib::Point (100, 100), 100);
	box.set_fill_color(Graph_lib::Color::red);
	box.move(100 , 100);
	win.attach(box);

	win.wait_for_button();
	return 0;
}
