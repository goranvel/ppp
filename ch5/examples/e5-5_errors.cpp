#include <iostream>

int area (int length, int width) {	// calculate area of a rectangle
	return length * width;
}

int framed_area (int x, int y) {		// calculate area within frame
	return area (x - 2, y - 2);
}

int main (void) {
	int x = -1;
	int y = 2;
	int z = 4;
	
	int area1 = area (x,y);
	int area2 = framed_area	(1, z);
	int area3 = framed_area (y, z);

	double ratio = double(area1)/area3;	// conver to double to get
													// float point division

	std::cout << area3 << " " << ratio << "\n";
	return 0;
}
