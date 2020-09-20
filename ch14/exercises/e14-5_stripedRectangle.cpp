#include "../../Simple_window.h"

namespace Graph_lib {
	class Stripped_rectangle : public Shape {
			unsigned width, height, line_w, space_w;
			Point corner;
		public:
			Stripped_rectangle (Point p, int w, int h, int l, int s) : 
									corner (p), width (w), height(h), line_w (l), space_w (s) {
				if (line_w < 1)
					line_w = 1;
			}

			void draw_lines () const {
				if ( fill_color().visibility() )
					for (int i = space_w; i < height; i += space_w)
						for (int j = space_w; j + line_w < width; j += space_w + line_w) {
							Line (Point(corner.x + j, corner.y + i), 
											Point (corner.x + line_w + j, corner.y + i)).draw();
						}

				fl_line (corner.x,corner.y,corner.x+width,corner.y);	
				fl_line (corner.x,corner.y,corner.x,corner.y+height);	
				fl_line (corner.x+width,corner.y,corner.x+width,corner.y+height);	
				fl_line (corner.x,corner.y+height,corner.x+width,corner.y+height);	
			}
	}; 
}

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Graph_lib");
	Graph_lib::Stripped_rectangle rect (Graph_lib::Point (100, 100), 100, 100, 30, 10); 
	rect.set_fill_color (Graph_lib::Color::red);
	win.attach(rect);
	rect.move(250, 205);	

	
	win.wait_for_button();

	
	return 0; 
}
