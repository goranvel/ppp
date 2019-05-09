#include "../../Simple_window.h"

namespace Graph_lib {
	class Face : public Circle {
			Ellipse l_eye, r_eye;
		public:
			Face (Point c, int r) :
					Circle (c, r),
					l_eye (Point (c.x + r * std::acos(-1) / 8 - 10, c.y - r * std::acos(-1) / 8), r/8, r/4),
					r_eye (Point (c.x - r * std::acos(-1) / 8 + 10, c.y - r * std::acos(-1) / 8), r/8, r/4)
			{
				l_eye.set_fill_color(Color::black);
				r_eye.set_fill_color(Color::black);
			}

			void draw_lines () const {
				Circle::draw_lines (); 
				l_eye.draw ();
				r_eye.draw ();
			}
	}; 

	class Smiley : public Face {
			Point center;
			int radius;
		public:
			Smiley (Point c, int r) : center (c), radius (r),
					Face (c, r) {
			}

			void draw_lines () const {
				Face::draw_lines();
				fl_arc  (center.x - radius, center.y - radius * 1.5, radius * 2, radius * 2 , 225.0, 315.0);	
			}
	}; // class smiley

	class Frowny : public Face {
			Point center;
			int radius;
		public:
			Frowny (Point c, int r) : center (c), radius (r),
					Face (c, r) {
			}

			void draw_lines () const {
				Face::draw_lines();
				fl_arc  (center.x - radius, center.y + radius / 4, radius * 2, radius * 2 , 45.0, 135.0);	
			}
	}; // class smiley


} // namespace Graph_lib

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Smiley and Frowny");

	Graph_lib::Smiley smiley (Graph_lib::Point (100, 100), 100);
	smiley.set_fill_color(Graph_lib::Color::yellow);
	win.attach (smiley);

	Graph_lib::Frowny frowny (Graph_lib::Point (200, 200), 100);
	frowny.set_fill_color(Graph_lib::Color::red);
	win.attach (frowny);

	win.wait_for_button();
	return 0;
}
