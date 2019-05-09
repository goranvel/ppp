#include "../../Simple_window.h"

namespace Graph_lib {
	struct My_fct : Shape { // did not use Fct since there is typedef in Graph.h with the same name :(
		Fct* function;
		double range_start, range_end, scale;
		Graph_lib::Point origin;
		int count;
		My_fct (Fct* f, double r1, double r2, Graph_lib::Point o, int c = 1000, double s = 50) : 
					function (f), range_start (r1), range_end(r2), origin(o), count (c), scale(s) {

			if (r1 >= r2) 	
				throw std::runtime_error ("Bad graphing range");
			if (count <= 0)
				throw std::runtime_error ("Count has to be greated than 0");

			initialize_points();
		}

		void initialize_points () {
			double point = range_start;
			double distance = (range_end - range_start)/count;
			for (int i = 0; i < count; ++i, point += distance)
				add (Point(origin.x + int(point * scale), origin.y - int(function (point) * scale)));
		}

		 void reset (Fct* f, double r1, double r2, Graph_lib::Point o, int c, double s) {
				function = f;
				range_start = r1;
				range_end = r2;
				origin = o;
				count = c;
				scale = s;
		 }
	};
}

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

	Graph_lib::My_fct f_sin (std::sin, range_start, range_end, origin, point_cnt, scale);
	f_sin.set_color(Graph_lib::Color::dark_green);
	win.attach (f_sin);

	Graph_lib::My_fct f_cos (std::cos, range_start, range_end, origin);
	f_cos.set_color(Graph_lib::Color::blue);
	win.attach (f_cos);

	win.wait_for_button();

	return 0;
}
