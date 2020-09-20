#include "../../Simple_window.h"

namespace Graph_lib {
	struct Scattered_graph : Shape {
		Axis x, y;

		Scattered_graph (int win_w, int win_h, vector <double> data, vector <double> vals) : 
					x (Axis::x, Point(100, win_h - 100), win_w - 200, 10, ""),
						y (Axis::y, Point(100, win_h - 100), win_h - 200, 10, "") {
			double y_max = findMax (vals);
			double y_min = findMin (vals);
			double x_max = findMax (data);
			double x_min = findMin (data);
			double y_scale = y_max/double(win_h - 200);
			double x_scale = (x_max - x_min)/double(win_w - 200);

			for (int i = 0; i < data.size(); ++i) {
				double y = win_h - 100 - vals[i] / y_scale;
				double x = 100 + (data[i] - x_min)/ x_scale;
				std::cout << x << " " << y << "\n";
				add(Point (x, y));
			} 
		}

		void draw_lines () const {
			x.draw_lines();
			y.draw_lines();
			Shape::draw_lines();
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
	};
} // namespace Graph_lib 

int main (void) {
	int win_w = 1920, win_h = 1080;
	vector<double> data =	{170, 175, 180, 185, 190, 195};
	vector<double> cnt	=	{7, 9, 3, 17, 6, 1};

	Simple_window win (Graph_lib::Point(1920, 0), win_w, win_h, "Heights");
	Graph_lib::Scattered_graph graph (win_w, win_h, data, cnt);

	win.attach(graph);
	win.wait_for_button(); 
	return 0;
}
