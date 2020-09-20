#include "../../Simple_window.h"

struct Distribution {
	int year, young, middle, old;
};

std::istream& operator>> (std::istream& is, Distribution& d) {
	char ch1 = 0, ch2 = 0, ch3 = 0;
	Distribution dd;

	if (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.middle >> dd.old >> ch3)
		if (ch1 != '(' || ch2 != ':' || ch3 != ')') {
			is.clear (std::ios_base::failbit);
			return is;
		}
//	else // << this might be an error in a book.
//		return is;
	
	d = dd;
	return is;
}

class Scale {
		int cbase;
		int vbase;
		double scale;
	public :
		Scale (int b, int vb, double s) : cbase (b), vbase (vb), scale (s) {
		}

		int operator () (int v) const {
			return cbase + (v - vbase) * scale;
		}
}; // class Scale;

namespace Graph_lib {
} // namespace Graph_lib
				
int main (void) {
	// setup
	const int win_w = 1920;
	const int win_h = 1080;

	const int xoffset = 100;
	const int yoffset = 100;

	const int xspace = 40;
	const int yspace = 40;

	const int xlength = 600 - xoffset - xspace; // length of axes
	const int ylength = 600 - yoffset - yspace;

	const int base_year = 1960;
	const int end_year = 2040;

	const double xscale = double (xlength) / (end_year - base_year);
	const double yscale = double (ylength) / 100;

	Simple_window win (Graph_lib::Point(1920, 0), win_w, win_h, "");

	Scale xs (xoffset, base_year,xscale);
	Scale ys (600 - yoffset, 0, -yscale);

	// Axis
	Graph_lib::Axis x (Graph_lib::Axis::x, Graph_lib::Point(xoffset, 600 - yoffset), xlength, (end_year - base_year)/10,
			"year  "
			"1960        1970        1980        1990        "
			"2000        2010        2020        2030        2040");
	x.set_color (Graph_lib::Color::red);
	x.label.move(-100, 0);
	win.attach(x);

	Graph_lib::Axis y (Graph_lib::Axis::y, Graph_lib::Point(xoffset, 600 - yoffset), ylength, 10, "\% of population");
	y.set_color (Graph_lib::Color::red);
	win.attach(y);

	Graph_lib::Line current_year (Graph_lib::Point(xs(2018), ys(0)), Graph_lib::Point(xs(2018), ys(100)));
	current_year.set_style(Graph_lib::Line_style::dash);
	win.attach(current_year);
	// Graphing 
	// Graph_lib::Point origin (x_orig, y_orig);

	Distribution d ();

	std::ifstream ifs ("japanese-age-data.txt");
	if (!ifs) 
		throw std::runtime_error ("can't open file");

	Graph_lib::Open_polyline children;
	children.set_color(Graph_lib::Color::red);

	Graph_lib::Open_polyline adults;
	adults.set_color(Graph_lib::Color::red);

	Graph_lib::Open_polyline aged;
	aged.set_color(Graph_lib::Color::red);

	for (Distribution d; ifs>>d;) {
		if (d.year < 1960 || d.year > 2040)
			throw std::runtime_error ("Year out of range");
		if (d.young + d.middle + d.old != 100)
			throw std::runtime_error ("Percentage do not add up");

		const int x = xs (d.year);
		children.add (Graph_lib::Point (x, ys(d.young)));
		adults.add(Graph_lib::Point(x,ys(d.middle)));
		aged.add(Graph_lib::Point(x, ys(d.old)));
	}

	win.attach (children);
	win.attach (adults);
	win.attach (aged);

	Graph_lib::Text children_label (Graph_lib::Point (10, children.point(0).y), "age 0 to 14");
	children_label.set_color(Graph_lib::Color::red);
	win.attach(children_label);

	Graph_lib::Text adults_label (Graph_lib::Point (10, adults.point(0).y), "age 15 to 64");
	adults_label.set_color(Graph_lib::Color::red);
	win.attach(adults_label);

	Graph_lib::Text aged_label (Graph_lib::Point (10, aged.point(0).y), "age 65+");
	aged_label.set_color(Graph_lib::Color::red);
	win.attach(aged_label);

	win.wait_for_button();

	Graph_lib::gui_main ();
	return 0;
}
