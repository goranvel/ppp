#include "../../Simple_window.h"

int main (void) {
	// setup
	const int win_w = 1920;
	const int win_h = 1080;

	const int x_orig = win_w/2;
	const int y_orig = win_h/2;

	const int range_start = -10;
	const int range_end = 10;

	const int point_cnt = 400;

	const int scale = 50;

	Simple_window win (Graph_lib::Point(1920, 0), win_w, win_h, "");

	// Axis
	Graph_lib::Axis x (Graph_lib::Axis::x, Graph_lib::Point((win_w - 1000)/2, y_orig), 1000, 1000/scale, "X");
	x.set_color (Graph_lib::Color::red);
	win.attach(x);

	Graph_lib::Axis y (Graph_lib::Axis::y, Graph_lib::Point(x_orig, (win_h + 1000)/2), 1000, 1000/scale, "Y");
	y.set_color (Graph_lib::Color::red);
	win.attach(y);

	// Graphing 
	Graph_lib::Point origin (x_orig, y_orig);

	win.wait_for_button();
	
	return 0;
}
