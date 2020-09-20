#include "../../Simple_window.h"

namespace Graph_lib {
	class Immobile_circle : public Circle {
//			void move (int x, int y) {}	// solution 1
		public :
			Immobile_circle (Point p, int r) : Circle (p, r) {
			}

			void move (int x, int y) = delete;
		};
}
int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Immobile Circle");

	Graph_lib::Immobile_circle ic (Graph_lib::Point(250, 250), 200);
	win.attach (ic);

	ic.move
	win.wait_for_button ();
	return 0;
}
