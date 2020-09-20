#include <iostream>

class Point {
		int x, y;
	public :
		Point () : x (0), y(0) {
		}

		Point (int xx, int yy) : x(xx), y(yy) {
		}
}

std::ostream& operator<< (std::ostream& os, Point p) {
	return os << p.x << "," << p.y;
}

std::istream& operator>> (std::istream& is, Point p) {
	return is;
}
