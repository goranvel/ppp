#include "../../Simple_window.h"

namespace Graph_lib {
	class Stripped_circle : public Shape {
			unsigned radius, line_w, space_w;
			Point center;
		public:
			Stripped_circle (Point p, int r, int l, int s) : 
									center (p), radius (r), line_w (l), space_w (s) {
				if (line_w < 1)
					line_w = 1;
			}

			void draw_lines () const {
				if ( fill_color().visibility() ) 
					for (int i = center.y - radius + space_w / 2; 
									i < center.y + radius - 1; i += space_w) {
						int square	= sqrt(radius * radius - (center.x - i) * (center.x - i));
						int begin	= center.x - square;
						int end		= center.x + square;

						for (int j = begin; j <= end; j += space_w + line_w) {
							if (j + line_w <= end)
								Line (Point(j, i), Point (j + line_w, i)).draw();
							else
								Line (Point(j, i), Point (end, i)).draw();

						}
					}

				fl_arc(center.x - radius, center.y - radius, radius << 1, radius << 1, 0, 360);
			}
	}; 
}

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Graph_lib");
	Graph_lib::Stripped_circle circ (Graph_lib::Point (100, 100), 100, 30, 10); 
	circ.set_fill_color (Graph_lib::Color::red);
	circ.move (50, 50);
	win.attach(circ); 
	
	win.wait_for_button(); 
	
	return 0; 
}
