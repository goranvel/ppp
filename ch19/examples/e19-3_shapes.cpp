#include <iostream>
#include "vector/Vector.h"

class Shape {
		std::string name;
	public :
		Shape (std::string n) : name (n) { }
};

class Circle : Shape {
		double radius;
	public :
		Circle (double r, std::string n) : 
			radius (r),
			Shape(n) {
		}
};

int main (void) {
	Vector<Shape> vint;
	Vector<Circle> vshort;
//	vint = vshort;

	Vector<Shape*> vpint;
	Vector<Circle*> vpshort;
//	vpint = vpshort;

	Vector<Shape&> vrint;
	Vector<Circle&> vrshort;
	return 0;
}
