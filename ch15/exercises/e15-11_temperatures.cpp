#include "../../Simple_window.h"

namespace Graph_lib {
	struct Y_Labels : Shape {
		vector <std::string> text;
		int x, y, y_difference, point_cnt;
		Y_Labels (int x, int y, int point_cnt, double min, 
					double max) : x (x - 50), y (y), text(point_cnt),
					y_difference((y - 500)/point_cnt), point_cnt (point_cnt) {
			for (int i = 0; i < point_cnt; ++i, min += (max - min) / 10) {
				text[i] = "" + to_string(int(min));
			}
		}

		Y_Labels () : point_cnt (0) {
		}

		void draw_lines () const {
			int y_pos = y - 83;
			for (int i = 0; i < point_cnt; ++i, y_pos -= 88)
				Text (Point (x, y_pos ), text[i]).draw_lines ();
		}
	}; // sturct Y_Label

	struct Scattered_graph : Shape {
			double findMax(vector <double> data ) const {
				double max = data[0];
				for (int i =0; i < data.size(); ++i)
					if (data[i] > max)
						max = data[i];

				return max;
			}

			int findMin(vector <double> data) const  {
				double min = data[0];
				for (int i = 0; i < data.size(); ++i)
					if (data[i] < min)
						min = data[i];

				return min;
			}

			void init (int win_w, int win_h, vector<double> vals) {
				double y_max = findMax (vals);
				double y_min = findMin (vals);
				double y_scale = y_max/double(win_h - 200);
				double x_scale = 12/double(win_w - 200);

				for (int i = 0; i < 12; ++i) {
					double y = win_h - 100 - vals[i] / y_scale;
					double x = 100 + i/x_scale;

					add(Point (x, y));
				}
			}

			Axis x, y;
			Y_Labels y_labels;

	public :
		Scattered_graph (int win_w, int win_h, vector <double> vals, std::string x_txt) : 
					x (Axis::x, Point(100, win_h - 100), win_w - 200, 12, x_txt),
						y (Axis::y, Point(100, win_h - 100), win_h - 200, 10, "Celsius"),
							y_labels (100, win_h - 100, 10, findMin(vals), findMax(vals)) {
			init (win_w, win_h, vals);
			x.label.move(-550, 0);
		}

		Scattered_graph (int win_w, int win_h, vector <double> vals) : 
					x (Axis::x, Point(100, win_h - 100), win_w - 200, 12, ""),
						y (Axis::y, Point(100, win_h - 100), win_h - 200, 10, ""),
							y_labels () {
			init (win_w, win_h, vals);
		}

		void draw_lines () const {
			x.draw_lines();
			y.draw_lines();
			Shape::draw_lines();
			y_labels.draw_lines();
		}

	
	}; // struct Scattered_graph
} // namespace Graph_lib 

void farToCel (vector <double> &);
std::string addSpaces (int n);

int main (void) {
	int win_w = 1920, win_h = 1080;
	vector<double> England =	
								{
									6.5,	6.9,	9.8,	12.2,
									16.1,	19.0,	21.7,	21.8,
									18.4,	14.1,	9.9,	7.7
								};

	vector<double> Massachusetts	=
								{
									37,		38,		45,		56,
									66,		76,		82,		80,
									73,		62,		52,		42
								};

	farToCel (Massachusetts);
	vector<std::string> months = {"Jan" , "Feb", "Mar", "Apr", "May", "Jun", "Jul", 
											"Aug", "Sep", "Oct", "Nov", "Dec"};
	std::string x_txt = "Month       ";

	for (int i; i < months.size(); ++i)
		x_txt += months[i] + addSpaces (40);
	

	std::string title = "Cambridge, England";
	Simple_window win (Graph_lib::Point(1920, 0), win_w, win_h, title);	
	Graph_lib::Scattered_graph england (win_w, win_h, England, x_txt);
	england.set_color (Graph_lib::Color::dark_green);

	Graph_lib::Scattered_graph massachusetts (win_w, win_h, Massachusetts);
	massachusetts.set_color (Graph_lib::Color::blue);
	Graph_lib::Point p (100, 100);

	win.attach(england);
	win.attach(massachusetts);

	win.wait_for_button();
	return 0;
}

void farToCel (vector <double> &data) {
	for (int i = 0; i < data.size(); ++i)
		data[i] = 5.0*(data[i] - 32)/9.0;
}

std::string addSpaces (int n) {
	std::string s;
	for (;n ; --n)
		s += " ";
	return s;
}
