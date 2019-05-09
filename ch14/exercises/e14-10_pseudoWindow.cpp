#include "../../Simple_window.h"
#include <stdexcept>

namespace Graph_lib {
	class Face : public Circle {
			Ellipse l_eye, r_eye;
		public:
			Face (Point c, int r) :
					Circle (c, r),
					l_eye (Point (c.x + r * std::acos(-1) / 8 - 10, c.y - r * std::acos(-1) / 8), r/8, r/4),
					r_eye (Point (c.x - r * std::acos(-1) / 8 + 10, c.y - r * std::acos(-1) / 8), r/8, r/4) {
				l_eye.set_fill_color(Color::black);
				r_eye.set_fill_color(Color::black);
				set_fill_color(Color::yellow);
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


	struct Pseudo_window : public Shape {
		int width, height;
		double radius;
		Point point;
		std::string title;
		Face face;

		Pseudo_window (Graph_lib::Point p, int w, int h, double rr, std::string t) :
				point (p), width (w), height (w), radius (rr), title (t),
						face(p, rr) {
			if (w <= 0 || height <= 0 || radius <= 0)
				throw std::runtime_error ("Width, height and radius have to be positive numbers");
		}

		void draw_lines () const {
			Smiley smiley (Point(point.y + width/2, point.y + height/2), width / 8);

			if (color().visibility()) {
				smiley.draw_lines();
				fl_color (color().as_int());
				fl_line	( point.x + radius, point.y, point.x - radius + width, point.y );
				fl_line	( point.x + radius, point.y + height, point.x - radius + width, point.y + height );
				fl_line	( point.x, point.y + radius, point.x, point.y - radius + height );
				fl_line	( point.x + width, point.y + radius, point.x + width, point.y - radius + height );

				fl_line	(point.x, point.y + radius, point.x + width, point.y + radius );
				fl_draw	(title.c_str(), point.x + width / 2, point.y + radius * 2 / 3 );	

				fl_arc	( point.x, point.y, radius * 2, radius * 2, 90, 180 );
				fl_arc	( point.x - radius * 2 + width, point.y,	radius * 2, radius * 2, 0, 90 );
				fl_arc	( point.x, point.y - radius * 2 + height, radius * 2, radius * 2, 180, 270 );
				fl_arc	( point.x - radius * 2 + width, point.y - radius * 2 + height, radius * 2, radius * 2, 270, 360 );
			}
		}

	}; // class Pseudo_window } // namespace Graph_lib

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 1000, 1000, "Pseudo_window");

	Graph_lib::Pseudo_window box (Graph_lib::Point (100, 100), 500, 500, 50, "Title");
	
	win.attach(box);

	win.wait_for_button();
	return 0;
}
