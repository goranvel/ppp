#include "../../Simple_window.h"

namespace Graph_lib {
	struct Y_Labels : Shape {
		vector <std::string> text;
		int x, y, y_difference;
		Y_Labels (int x, int y, int point_cnt, double min, double max) : x (x - 50), y (y), text(point_cnt),
					y_difference((y - 500)/point_cnt) {
			for (int i = 0; i < point_cnt; ++i, min += (max - min) / 10) {
				text[i] = "" + to_string(int(min));
			}
		}

		void draw_lines () const {
			int y_pos = y - 83;
			for (int i = 0; i < 10; ++i, y_pos -= 88)
				Text (Point (x, y_pos ), text[i]).draw_lines ();
		}
	};

	struct Scattered_graph : Shape {
		Axis x, y;
		Y_Labels y_labels;

		Scattered_graph (int win_w, int win_h, vector <double> data, vector <double> vals, 
							std::string x_txt, std::string y_txt) : 
					x (Axis::x, Point(100, win_h - 100), win_w - 200, data.size(), x_txt),
						y (Axis::y, Point(100, win_h - 100), win_h - 200, 10, "$"),
							y_labels (100, win_h - 100, vals.size(), findMin(vals), findMax(vals)) {
			double y_max = findMax (vals);
			double y_min = findMin (vals);
			double x_max = findMax (data);
			double x_min = findMin (data);
			double y_scale = y_max/double(win_h - 200);
			double x_scale = (x_max - x_min)/double(win_w - 200);

			for (int i = 0; i < vals.size(); ++i) {
				double y = win_h - 100 - vals[i] / y_scale;
				double x = 100 + (data[i] - x_min)/ x_scale;

				add(Point (x, y));
			}

			x.label.move(-475, 0);
		}

		void draw_lines () const {
			x.draw_lines();
			y.draw_lines();
			Shape::draw_lines();
			y_labels.draw_lines();
		}

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
	}; // struct Scattered_graph
} // namespace Graph_lib 

int main (void) {
	int win_w = 1920, win_h = 1080;
	vector<double> vals =	{
								2021, 1999, 1981, 1949,	1917,	
								1874, 1859, 1857, 1724, 1808,
								1795, 1783, 1842, 1821, 1785,
								1784, 1742, 1773, 1703, 1649,
								1660, 1486, 1568
							};

	vector<double> days;

	for (int i = 0, j = 0; i < 31; ++i, ++j) {
		days.push_back(i);
		if (!((i + 1) % 7))
			i+=2;
	}

	std::string x_txt = "Date"
			"          10/1               10/2              10/3               10/4               10/5"
		"               10/8               10/9             10/10            10/11            10/12"
			"            10/15            10/16            10/17            10/18            10/19"
			"            10/22            10/23            10/24            10/25            10/26"
			"            10/29            10/30            11/31";

	std::string title = "Amazon Stock Prices";
	Simple_window win (Graph_lib::Point(1920, 0), win_w, win_h, title);	
	Graph_lib::Scattered_graph graph (win_w, win_h, days, vals, x_txt, "");
	Graph_lib::Point p (100, 100);
//	Graph_lib::Text t (p, "hell");

	win.attach(graph);
	win.wait_for_button();
	return 0;
}
