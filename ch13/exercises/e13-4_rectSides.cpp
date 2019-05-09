#include "../../Simple_window.h"

namespace Graph_lib {
	Point n (const Graph_lib::Rectangle &r) {
		return Graph_lib::Point (r.point (0).x + r.width() >> 1, r.point(0).y);
	}

	Point s (const Graph_lib::Rectangle &r) {
		return Graph_lib::Point (r.point (0).x + r.width() >> 1, r.point(0).y + r.height());
	}

	Point e (const Graph_lib::Rectangle &r) {
		return Graph_lib::Point (r.point (0).x + r.width(), r.point(0).y + r.height() >> 1);
	}

	Point w (const Graph_lib::Rectangle &r) {
		return Graph_lib::Point (r.point (0).x, r.point(0).y + r.height() >> 1);
	}

	Point ne (const Graph_lib::Rectangle &r) {
		return Graph_lib::Point (r.point (0).x + r.width(), r.point(0).y);
	}

	Point se (const Graph_lib::Rectangle &r) {
		return Graph_lib::Point (r.point (0).x + r.width(), r.point(0).y + r.height());
	}

	Point sw (const Graph_lib::Rectangle &r) {
		return Graph_lib::Point (r.point (0).x, r.point(0).y + r.height());
	}

	Point nw (const Graph_lib::Rectangle &r) {
		return r.point (0);
	}

	Point e (const Graph_lib::Rectangle &r) {
		return Graph_lib::Point (r.point (0).x + r.width(), r.point(0).y + r.height() >> 1);
	}
}

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 300, 300, "window");
	Graph_lib::Rectangle r (Graph_lib::Point (100, 100), 50, 50);

	std::cout	<< Graph_lib::e(r).x << " " << Graph_lib::e(r).y << " "
					<< Graph_lib::w(r).x << " " << Graph_lib::w(r).y << " "
					<< Graph_lib::n(r).x << " " << Graph_lib::n(r).y << " "
					<< Graph_lib::s(r).x << " " << Graph_lib::s(r).y;

	win.attach (r);
	win.wait_for_button ();
	return 0;
}
