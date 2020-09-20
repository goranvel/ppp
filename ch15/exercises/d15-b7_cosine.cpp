#include "../../Simple_window.h"

double slope	(double x);
double square	(double x);

int main (void) {
	// setup part
	const int win_w = 1920;
	const int win_h = 1080;

	const int x_orig = win_w/2;
	const int y_orig = win_h/2;

	const int range_start = -10;
	const int range_end = 10;

	const int point_cnt = 400;

	const int scale = 50;

	Simple_window win (Graph_lib::Point(1920, 0), win_w, win_h, "Basic Graphs");

	// Axis setup
	Graph_lib::Axis x (Graph_lib::Axis::x, Graph_lib::Point(x_orig - 1000/2, y_orig), 1000, 1000/scale, "X");
	x.set_color (Graph_lib::Color::red);
	win.attach(x);

	Graph_lib::Axis y (Graph_lib::Axis::y, Graph_lib::Point(x_orig, y_orig + 1000/2), 1000, 1000/scale, "Y");
	y.set_color (Graph_lib::Color::red);
	win.attach(y);

	// Graphing part
	Graph_lib::Point origin (x_orig, y_orig);

	Graph_lib::Function f_slope (slope, range_start, range_end, origin, point_cnt, scale, scale);
	win.attach(f_slope);

	Graph_lib::Text slope_label (Graph_lib::Point (x_orig + range_start * scale - 25, 
														y_orig - slope(range_start)*scale + 25),
									"x/2");
	win.attach (slope_label);


	Graph_lib::Function f_square (square, -std::sqrt(-range_start), std::sqrt(range_end), 
											origin, point_cnt, scale, scale);
	win.attach (f_square);

	Graph_lib::Text	square_label (Graph_lib::Point (x_orig-std::sqrt(-range_start) * scale - 25, 
													 y_orig - square (-range_start) * scale/10 + 25), 
								"x^2");
	win.attach (square_label);


	Graph_lib::Function f_cosine (std::cos, range_start, range_end, origin, point_cnt, scale, scale);
	win.attach(f_cosine);

	Graph_lib::Text cosine_label (Graph_lib::Point (x_orig + range_start * scale - 25, 
														y_orig - std::cos(range_start)*scale + 25),
									"cos(x)");
	win.attach (cosine_label);

	win.wait_for_button(); 

	return 0;
}

double slope (double x) {
	return x/2;
}

double square (double x) {
	return x * x;
}
