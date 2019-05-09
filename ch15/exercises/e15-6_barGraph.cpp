#include "../../Simple_window.h"

namespace Graph_lib {
	struct Bar : Rectangle {
		Bar (Point p, int h, int w = 20) : Rectangle (Graph_lib::Point(p.x - w/2, p.y - h), w, h + 1) {
			std::cout << "H : " << h << "\n";
			set_color (Graph_lib::Color::blue);
		}

		void set_color (Graph_lib::Color c) {
			Rectangle::set_color (c);
			Rectangle::set_fill_color (c);
		}
	};

	struct Bar_graph : public Shape {
		Axis x, y;
		vector<double> data;
		Point center;
		int width, height;

		Bar_graph (int win_w, int win_h, vector<double> data) : width (win_w - 200), height (win_h - 200), 
					data (data), center (Point (100, win_h - 100)),
						x (Axis::x, Point(100, win_h - 100), win_w - 200, 10, "x"),
							y (Axis::y, Point(100, win_h - 100), win_h - 200, 10, "y") { 
		}

 		Bar_graph (Point center, int win_w, int win_h, vector<double> data) : width (win_w - 200), height (win_h), data (data), 
						x (Axis::x, Point(100, win_h - 100), width, 10, "x"),
							y (Axis::y, Point(100, win_h - 100), height, 10, "y") { 
		}
 
		void draw_lines () const {
			x.draw_lines ();
			y.draw_lines ();
			int max = findMax();
			int min = findMin(); 
			for (int i = 0; i < data.size(); ++i) {
				std::cout << ">> " << (data[i]-min)*10/(max - min) << " " << "\n";
				Bar(Point(center.x + width/10 + i * width/10, center.y), (data[i] - min)*100/(max - min)).draw_lines();
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
	Simple_window win (Graph_lib::Point(1920,0), win_w, win_h, "Graph Bar");
	Graph_lib::Bar_graph g (win_w, win_h, d );

	win.attach (g);
	win.wait_for_button();

	return 0;
}
