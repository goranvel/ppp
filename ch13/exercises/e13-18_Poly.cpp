#include "../../Simple_window.h"

namespace Graph_lib {
	struct Poly : Polygon {
		Poly (vector<Point> ps) {
			if (ps.size() < 3)
				throw std::runtime_error ("Polygon has to have at list three corners.\n");
			for (int i = 0; i + 3 < ps.size(); i++) {
				if ((ps[i + 2].y - ps[i + 1].y) * (ps[i + 1].x - ps[i].x) -
						(ps[i + 2].x - ps[i + 1].x) * (ps[i + 1].y - ps[i].y) == 0) {
					throw std::runtime_error ("Lines intersect");
				}
			}

			for (int i = 0; i < ps.size(); ++i) {
				Polygon::add (ps[i]);
			}
		}
		
		void draw () {
			Polygon::draw();
		}
	}; // struct Poly
} // namepsace Graph_lib

int main () {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Right Triangle");

	vector<Graph_lib::Point> ps = {
		Graph_lib::Point (100, 100), 
		Graph_lib::Point (150, 100),
		Graph_lib::Point (150, 150), 
		Graph_lib::Point (100, 150)
	};
	
	Graph_lib::Poly poly (ps);
	win.attach(poly);
	win.wait_for_button ();

	return 0;
}
