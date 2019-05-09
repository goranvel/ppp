#include "../../Simple_window.h"
#include <vector>

int main (void) {
	Graph_lib::Point p (1900, 0);

	Simple_window win (p, 1000, 800, "CH 13 Drill 1");

	// adds grid
	Graph_lib::Lines lines;
	for (int i = 0, points = 0; i < 8; ++i, points += 100)
		lines.add(Graph_lib::Point (points, 0), Graph_lib::Point (points, 800));

	for (int i = 0, points = 0; i < 8; ++i, points += 100)
		lines.add(Graph_lib::Point (0, points), Graph_lib::Point (800, points));
	win.attach (lines);
/*	
	Graph_lib::Image img1 (Graph_lib::Point(0,0), "image.jpg");
	img1.set_mask(Graph_lib::Point(0, 0), 200, 200);
	win.attach (img1);
	Graph_lib::Image img2 (Graph_lib::Point(0,600), "image.jpg");
	img2.set_mask(Graph_lib::Point(0, 0), 200, 200);
	win.attach (img2);
	Graph_lib::Image img3 (Graph_lib::Point(600,0), "image.jpg");
	img3.set_mask(Graph_lib::Point(0, 0), 200, 200);
	win.attach (img3); */
	Graph_lib::Image img4 (Graph_lib::Point(0,0), "image.jpg");
	img4.set_mask(Graph_lib::Point(275, 75), 100, 100);
	win.attach(img4);
	win.wait_for_button();	

	for (int j = 0; j < 64; ++j) {
		img4.move(100, 0);

		if (!((j + 1) % 8) && j)
		  img4.move (-800, 100);

 		win.wait_for_button();
	}

	return 0;
}
