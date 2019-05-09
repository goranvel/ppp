#include "../../Simple_window.h"
#include <cmath>

namespace Graph_lib {

struct Arrow : Shape {
	Lines arrow;
	Arrow (Point start, int len, double angle) {
		Point end (	start.x + int (std::cos (angle * std::acos(-1)/180) * len), 
							start.y + int (std::sin (angle * std::acos(-1)/180) * len));
		arrow.add (start, end);

		add_short_lines (end, angle);
	}

	Arrow (Point start, Point endPoint) {
		arrow.add (start, endPoint);

		double angle = std::atan((endPoint.y - start.y)*1.0/(endPoint.x - start.x)) * 180/std::acos(-1);
		if (endPoint.y < start.y && endPoint.x < start.x || endPoint.y > start.y && endPoint.x < start.x)
			angle += 180;
		if (endPoint.y < start.y && endPoint.x > start.x)
			angle += 360;

		add_short_lines (endPoint, angle);
	}

	void add_short_lines (Point p, double angle) {
  		int side1_x = int (p.x - std::cos ((angle + 45) * std::acos(-1)/180) * 20);
		int side1_y = int (p.y - std::sin ((angle + 45) * std::acos(-1)/180) * 20);

		int side2_x = int (p.x - std::cos ((angle - 45) * std::acos(-1)/180) * 20);
		int side2_y = int (p.y - std::sin ((angle - 45) * std::acos(-1)/180) * 20);

		arrow.add (p, Point(side1_x, side1_y));
		arrow.add (p, Point(side2_x, side2_y));
	}

	void draw_lines() const {
		arrow.draw_lines ();
	}
};

}

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 1080), 200, 200, "Window");
	Graph_lib::Arrow a (Graph_lib::Point (100, 100), 50, 225);
	Graph_lib::Arrow b (Graph_lib::Point (150, 100), Graph_lib::Point (250, 50));
	win.attach (a);
	win.attach (b);
	win.wait_for_button();
	return 0;
}
