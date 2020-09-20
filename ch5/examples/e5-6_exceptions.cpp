#include <iostream>

class Bad_area {};

int area				(int l, int w);
int framed_area	(int l, int w);

int main (void) 
try {
	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area (x, y);
	int area2 = framed_area (1, x);
	int area3 = framed_area (y, z);
	return 0;
} catch (Bad_area) {
	std::cout << "Ooops bad arguments to area()\n";
}

int area (int l, int w) {
	if (l <= 0 || w <= 0)
		throw Bad_area();

	return l * w;
}

int framed_area (int l, int w) {
	return area (l - 2, w - 2);
}
