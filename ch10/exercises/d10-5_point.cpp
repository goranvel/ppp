#include <iostream>
#include <vector>
#include <fstream>

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
	return os << p.getX() << " " << p.getY();
}

std::istream& operator>> (std::istream& is, Point& p) {
	int x = 0, y = 0;
	while (true) {
		is >> x >> y;
		if (is.fail()) {
			std::cerr << "ERROR: invalid point\n";
			is.clear();
			is.unget();
			for (char ch; is >> ch && !isdigit(ch););
			break;
		} else
			break;
	} 

	p.setX(x);
	p.setY(y);

	return is;
}

bool operator== (Point& p1, Point& p2) {
	return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}

bool operator!= (Point& p1, Point& p2) {
	return p1.getX() != p2.getX() || p1.getY() != p2.getY();
}

int main () {
	std::cout << "Please enter seven point (ie. two numbers followed by whitespace)\n";
	std::vector<Point> original_point;
	std::vector<Point> processed_point;

	std::ofstream ofs ("mydata.txt");

	Point p;
	for  (int i = 7; i; --i) {
		std::cin >> p;
		original_point.push_back(p);
	}

	for (int i = original_point.size(); i; --i)
		ofs << original_point[7 - i] << "\n";

	ofs.close();

	std::ifstream ifs ("mydata.txt");
	for (int i = 7; i && ifs >> p; --i) {
		processed_point.push_back(p);
	}

	return 0;
}
