#include <iostream>
#include <vector>

class Point {
		int x, y;
	public :
		Point () : x (0), y(0) {
		}

		Point (int xx, int yy) : x(xx), y(yy) {
		}

		int getX() {
			return x;
		}
		
		int getY() {
			return y;
		}

		void setX (int xx) {
			x = xx;
		}

		void setY (int yy) {
			y = yy;
		}
};

std::ostream& operator<< (std::ostream& os, Point p) {
	return os << p.getX() << "," << p.getY();
}

std::istream& operator>> (std::istream& is, Point& p) {
	int x = 0, y = 0;
	while (true) {
		std::cin >> x >> y;
		if (std::cin.fail()) {
			std::cerr << "ERROR: invalid point\n";
			std::cin.clear();
			for (char ch; std::cin >> ch && !isdigit(ch););
			std::cin.unget();
		} else
			break;
	} 

	p.setX(x);
	p.setY(y);

	return is;
}

int main () {
	std::cout << "Please enter seven point (ie. two numbers followed by whitespace)\n";
	std::vector<Point> original_point;

	Point p;
	for  (int i = 7; i; --i) {
		std::cin >> p;
		original_point.push_back(p);
	}

	return 0;
}
