#include "../../Simple_window.h"

namespace Graph_lib {
	int distance (const Circle& c) {
		return std::sqrt (c.radius()*c.radius()/2);
	}

	int distance (const Ellipse& e) {
		int min = e.minor ();
		int max = e.major ();

		return min * max / std::sqrt(max * max + min * min);
	}

	Point n (const Graph_lib::Circle &c) {
		return Graph_lib::Point (c.center().x, c.center().y + c.radius());
	}

	Point s (const Graph_lib::Circle &c) {
		return Graph_lib::Point (c.center().x, c.center().y - c.radius());
	}

	Point e (const Graph_lib::Circle &c) {
		return Graph_lib::Point (c.center().x + c.radius(), c.center().y);
	}

	Point w (const Graph_lib::Circle &c) {
		return Graph_lib::Point (c.center().x - c.radius(), c.center().y);
	}

	Point ne (const Graph_lib::Circle &c) {
		int dist = distance (c);
		return Graph_lib::Point (c.center().x + dist, c.center().y - dist);
	}

	Point se (const Graph_lib::Circle &c) {
		int dist = distance (c);
		return Graph_lib::Point (c.center().x + dist, c.center().y + dist);
	}

	Point nw (const Graph_lib::Circle &c) {
		int dist = distance (c);
		return Graph_lib::Point (c.center().x - dist, c.center().y - dist);
	}

	Point sw (const Graph_lib::Circle &c) {
		int dist = distance (c);
		return Graph_lib::Point (c.center().x - dist, c.center().y + dist);
	}

	Point n (const Graph_lib::Ellipse &e) {
		return Graph_lib::Point (e.center().x, e.center().y + e.minor());
	}

	Point s (const Graph_lib::Ellipse &e) {
		return Graph_lib::Point (e.center().x, e.center().y - e.minor());
	}

	Point e (const Graph_lib::Ellipse &e) {
		return Graph_lib::Point (e.center().x + e.major(), e.center().y);
	}

	Point w (const Graph_lib::Ellipse &e) {
		return Graph_lib::Point (e.center().x - e.major(), e.center().y);
	}

	Point ne (const Graph_lib::Ellipse &e) {
		int dist = distance (e);
		return Graph_lib::Point (e.center().x + dist, e.center().y - dist);
	}

	Point se (const Graph_lib::Ellipse &e) {
		int dist = distance (e);
		return Graph_lib::Point (e.center().x + dist, e.center().y + dist);
	}

	Point nw (const Graph_lib::Ellipse &e) {
		int dist = distance (e);
		return Graph_lib::Point (e.center().x - dist, e.center().y - dist);
	}

	Point sw (const Graph_lib::Ellipse &e) {
		int dist = distance (e);
		return Graph_lib::Point (e.center().x - dist, e.center().y + dist);
	}

}

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 300, 300, "window");
	Graph_lib::Circle c (Graph_lib::Point (100, 100), 50);

	std::cout	<< "N: " << Graph_lib::n(c).x << " " << Graph_lib::n(c).y << " "
					<< "S: " << Graph_lib::s(c).x << " " << Graph_lib::s(c).y << " "

					<< "E: " << Graph_lib::e(c).x << " " << Graph_lib::e(c).y << " "
					<< "W: " << Graph_lib::w(c).x << " " << Graph_lib::w(c).y << "\n";
	win.attach(c);

	Graph_lib::Ellipse e (Graph_lib::Point (100, 100), 50, 100);

	std::cout	<< "NW: " << Graph_lib::nw(e).x << " " << Graph_lib::nw(e).y << " "
					<< "SW: " << Graph_lib::sw(e).x << " " << Graph_lib::sw(e).y << " "

					<< "NE: " << Graph_lib::ne(e).x << " " << Graph_lib::ne(e).y << " "
					<< "SE: " << Graph_lib::se(e).x << " " << Graph_lib::se(e).y;


	win.attach (e);
	win.wait_for_button ();
	return 0;
}
