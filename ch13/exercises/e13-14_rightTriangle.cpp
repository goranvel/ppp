#include "../../Simple_window.h"

namespace Graph_lib {
	struct RightTriangle : Shape {
		Point A, B, C; // corners
		int a, b; // sides
		RightTriangle (Point CC, int aa, int bb) : C (CC), a (aa), b (bb) {
			A = Point (C.x, C.y + b);
			B = Point (C.x + a, C.y);
		}

		void draw_lines () const {
			if (fill_color().visibility()) {
				fl_color (fill_color().as_int());
				fl_begin_complex_polygon();

				fl_vertex (A.x, A.y);
				fl_vertex (B.x, B.y);
				fl_vertex (C.x, C.y);

				fl_end_complex_polygon();
			}

			if (color().visibility()) {
				fl_color (color().as_int());

				fl_line (A.x, A.y, B.x, B.y);
				fl_line (B.x, B.y, C.x, C.y);
				fl_line (C.x, C.y, A.x, A.y);
			}
		}
	}; // struct RightTriangle
} // namespace Graph_lib

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Right Triangle");

	Graph_lib::RightTriangle r (Graph_lib::Point(200,200), 100, 50);
	r.set_fill_color (Graph_lib::Color::red);
	win.attach(r);

	win.wait_for_button();
}
