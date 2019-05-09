#include "../../Simple_window.h"

namespace Graph_lib {
	class Triangle : Closed_polyline {
		public :
			Triangle (Point t, int h, int w)  {
				add (t);
				add (Point (t.x - w/2, t.y + h));
				add (Point (t.x + w/2, t.y + h));
			}

			Point top() {
				return point (0);
			}

			Point bottomLeft () {
				return point (1);
			}

			Point bottomRight () {
				return point (2);
			}

			void draw_lines() const {
				Closed_polyline::draw_lines();	
			}

	}; // class Triangle

	class Binary_tree : public Shape {
			int levels;
			vector<Point> nodes;
		public :
			Binary_tree (int l) : levels (l) {
				int h_pos = 500; // half of windows width 
				int screen_h = 500;
				int nodeCnt = 1;
				int v_pos = screen_h/levels/2;

				for (int i = 0; i < levels; ++i, h_pos /= 2, nodeCnt *= 2, v_pos += screen_h/levels) {
					for (int j = 0, pos = h_pos/2; j < nodeCnt; ++j, pos += h_pos) {
						nodes.push_back (Point (pos, v_pos));
					}
				}
			}

			virtual void draw_lines () const {
				for (int i = 0; i < nodes.size(); ++i) {
					Circle c (nodes[i], 5);
					c.draw_lines();

					if (i > 0) 
						Line (Point(nodes[i].x, nodes[i].y - 5), 
								Point(nodes[(i - 1)/2].x + (i % 2 ? -5 : 5), nodes[(i - 1)/2].y)).draw();
				}
			}

			vector<Point> getNodes () const {
				return nodes;
			}
	}; // class Binary_tree

	class Binary_tree_triangle : public Binary_tree {
		public :
			Binary_tree_triangle (int l) : Binary_tree (l) { 
			}

			void draw_lines () const override {
				vector<Point> nodes = getNodes();
				for (int i = 0; i < nodes.size(); ++i) {
					Triangle current (nodes[i], 20, 20);
					current.draw_lines ();

					if (i > 0)  {
						Triangle parent (nodes[(i - 1)/2], 20, 20);
						Line (i%2 ? parent.bottomLeft() : parent.bottomRight(), current.top()).draw();
					}
				}
			}
	}; // class Binary_tree_triangle
} // namespace Graph_lib

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Binary tree");

	Graph_lib::Binary_tree_triangle t (5);
	win.attach(t);

	win.wait_for_button();
	return 0;
}
