#include "../../Simple_window.h"

using FctLambda = std::function<double(double)>;

namespace Graph_lib {
	struct My_function : Shape {
		My_function (FctLambda f, double r1, double r2, Point origin,
						int count = 1000, double xscale = 50, double yscale = 50) {
			if (r1 >= r2)
				throw std::runtime_error ("Bad graphing range");
			if (count <= 0)
				throw std::runtime_error ("Cout has to be greather than 0");
			
			double dist = (r2 - r1)/count;

			for (int i = 0; i < count; ++i, r1 += dist)
				add (Point(origin.x + int(r1 * xscale), origin.y - int(f(r1) * yscale)));
		}
	}; // sturct My_function
} // namespace Graph_lib

double fact (int n );
double term (double x, int n);
double expe (double x, int n);

int main (void) {
	// setup
	const int win_w = 1920;
	const int win_h = 1080;

	const int x_orig = win_w/2;
	const int y_orig = win_h/2;

	const int range_start = -10;
	const int range_end = 10;

	const int point_cnt = 400;

	int scale = 50;

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

//	Graph_lib::Function real_exp ([](double) {return 0;}, range_start, range_end, origin, scale, scale);
//	real_exp.set_color(Graph_lib::Color::blue);

//	std::ostringstream ss;
	for (int n = 0; n < 50; ++n) {
		std::ostringstream ss;
		ss << "exp approximation; n = " << n; 
		win.set_label (ss.str());

		Graph_lib::Function real_exp ([n] (double x) {return expe (x, n);}, range_start, range_end, 
					origin, point_cnt, scale, scale);

//		Graph_lib::My_function real_exp ([n] (double x) {return x/2;}, range_start, range_end, 
//					origin, point_cnt, scale, scale);
	
		real_exp.set_color (Graph_lib::Color::blue);

		win.attach (real_exp);
		win.wait_for_button();
		win.detach (real_exp);
	}

//	win.wait_for_button();

	return 0;
}

double fact (int n) {
	int r = 1;
	for (; n > 1; r *= n, --n);

	return r;
}

double term (double x, int n) {
	return std::pow(x, n)/fact(n);
}

double expe (double x, int n) {
	double sum = 0;
	for (int i = 0; i < n; ++i)
		sum += term (x, i);

	return sum;
}
