#include "../../Simple_window.h"

double leibniz (double);

int main (void) {
	// setup
	constexpr int win_w = 1920;
	constexpr int win_h = 1080;

	constexpr int x_orig = win_w/2;
	constexpr int y_orig = win_h/2;

	constexpr int range_start = -10;
	constexpr int range_end = 10;

	constexpr int point_cnt = 400;

	constexpr int scale = 50;

	Simple_window win (Graph_lib::Point(1920, 0), win_w, win_h, "Leibinz");

	// Axis
	Graph_lib::Axis x (Graph_lib::Axis::x, Graph_lib::Point((win_w - 1000)/2, y_orig), 1000, 1000/scale, "X");
	x.set_color (Graph_lib::Color::red);
	win.attach(x);

	Graph_lib::Axis y (Graph_lib::Axis::y, Graph_lib::Point(x_orig, (win_h + 1000)/2), 1000, 1000/scale, "Y");
	y.set_color (Graph_lib::Color::red);
	win.attach(y);

	// Graphing 
	Graph_lib::Point origin (x_orig, y_orig);

//	std::ostringstream ss;
	for (int n = 1; n < 50; ++n) {
		std::ostringstream ss;
		ss << "Leibniz approximation; n = " << n; 
		win.set_label (ss.str());

        Graph_lib::Function real_exp(leibniz, range_start, range_end, origin, n, scale, scale);
		real_exp.set_color (Graph_lib::Color::blue);

		win.attach (real_exp);
		win.wait_for_button();
		win.detach (real_exp);

//		std::cout << leibniz (n) << "\n";
	}

//	win.wait_for_button();

	return 0;
}

double leibniz (double n) {
	double sum = 0;
	int sign = 1;
	int den = 1;

	for (int i = 1; i <= n; ++i, sign *= -1) {
		sum += sign/double(i);
	}

	return sum;

}
