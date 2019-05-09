#include "../../Simple_window.h"

namespace Graph_lib {
	struct Bar : Rectangle {
		Point point;
		Color color;
		std::string label;
		Bar (Point p, int h, int w = 20, std::string label = "", Graph_lib::Color color=Graph_lib::Color::blue) : 
				point (Point (p.x - w/2, p.y - h - 5)), color (color), label (label),
					Rectangle (Graph_lib::Point(p.x - w/2, p.y - h), w, h + 1) {
			// constructor
		}

		void set_color (Graph_lib::Color c) {
			Rectangle::set_color (c);
			Rectangle::set_fill_color (c);
		}

		void draw_lines () {
			Text t1 (point, label);
			t1.set_color(Color::black);
			t1.draw();
			set_color (color);
			Rectangle::draw_lines();
		}

	};

	struct Bar_graph : public Shape {
		Axis x, y;
		vector<double> data;
		Point center;
		int width, height;
		vector<std::string> labels;

		Bar_graph (int win_w, int win_h, vector<double> data, vector<std::string> labels) : 
					width (win_w - 200), height (win_h - 200), 
						data (data), labels(labels), center (Point (100, win_h - 100)),
							x (Axis::x, Point(100, win_h - 100), win_w - 200, 10, ""),
								y (Axis::y, Point(100, win_h - 100), win_h - 200, 10, "") { 
			if (data.size() != labels.size())
				throw std::runtime_error ("Data and labels are not the same size");
		}

 		Bar_graph (Point c, int win_w, int win_h, vector<double> data, vector<std::string> labels) : 
					Bar_graph (win_w, win_h, data, labels) {
			center = c;	
		}
 
		void draw_lines () const {
			x.draw_lines ();
			y.draw_lines ();
			int max = findMax();
			int min = findMin(); 
			for (int i = 0; i < data.size(); ++i) {
				Bar(Point(center.x + width/10 + i * width/10, center.y), 
						(data[i] - min)*200/(max - min), 20, to_string(int(data[i]))).draw_lines();

				Text t1 (Point(center.x + width/10 - 13 + i * width/10, center.y + 15), labels[i]);
				t1.set_color(Color::black);
				t1.draw();
			}
		}

		int findMax() const {
			int max = data[0];
			for (int i = 0; i < data.size(); ++i)
				if (data[i] > max)
					max = data[i];

			return max;
		}

		int findMin () const {
			int min = data[0];
			for (int i = 0; i < data.size(); ++i)
				if (data[i] < min)
					min = data[i];

			return min;
		}

	}; // class Bar_graph
} //  namespace Graph_lib

int main (void) {
	const int win_w = 600;
	const int win_h = 400;

	vector<double> d = {2025, 2047, 2038, 2006, 1973};
	vector<std::string> days = {"Mon", "Tue", "Wed", "Thu", "Fri"};
	Simple_window win (Graph_lib::Point(1920,0), win_w, win_h, "Amazon Stock Pricees last week");
	Graph_lib::Bar_graph g (win_w, win_h, d, days);

	win.attach (g);
	win.wait_for_button();

	return 0;
}
