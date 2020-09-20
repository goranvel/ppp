#include "../../Simple_window.h" 
namespace Graph_lib {
	struct Star : Closed_polyline {
		Point center;
		int corners;
		int width;

		Star (Point p, int c, int w) : center (p), corners (c), width (w) {
			if (c < 3)
				throw std::runtime_error ("Star has to have 3 points");

			for (int i = 0; i < corners * 2; ++i) {
				Point p ( center.x + (i % 2 ? width/2 : width) * std::cos (2 * i * std::acos(-1)/(corners * 2)),
							center.y + (i % 2 ? width/2 : width) * std::sin (2 * i * std::acos(-1)/(corners * 2)));
				add(p);
			}		
		}

		void draw () {
			Closed_polyline::draw();
		}
	};
}

int main (void) {
    Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Star");

    Graph_lib::Star star (Graph_lib::Point (100, 100), 5, 100); 
    star.set_fill_color(Graph_lib::Color::red);
    win.attach(star);

    win.wait_for_button();

	return 0;
}
