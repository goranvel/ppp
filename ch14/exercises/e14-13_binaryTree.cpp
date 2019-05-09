#include "../../Simple_window.h"

namespace Graph_lib {
	enum class LineType { up, down, both, none };

	struct Arrow : Shape {
		Lines arrow;
		Arrow (Point start, int len, double angle) {
			Point end (	start.x + int (std::cos (angle * std::acos(-1)/180) * len), 
								start.y + int (std::sin (angle * std::acos(-1)/180) * len));
			arrow.add (start, end);

			add_short_lines (end, angle);
		}

		Arrow (Point start, Point endPoint, LineType type) {
			arrow.add (start, endPoint);

			if (type == LineType::none)
				return;

			double angle = std::atan((endPoint.y * 1.0 - start.y)/(endPoint.x - start.x)) * 180/std::acos(-1);

			if (endPoint.y < start.y && endPoint.x < start.x || endPoint.y > start.y && endPoint.x < start.x)
				angle += 180;
			if (endPoint.y < start.y && endPoint.x > start.x)
				angle += 360;
		
			if (type == LineType::down)
				add_short_lines (endPoint, angle);
			else if (type == LineType::up)
				add_short_lines (start, angle+180);
			else if (type == LineType::both) {
				add_short_lines (endPoint, angle);
				add_short_lines (start, angle+180);
			}


		}

		void add_short_lines (Point p, double angle) {
			int side1_x = int (p.x - std::cos ((angle + 20) * std::acos(-1)/180) * 20);
			int side1_y = int (p.y - std::sin ((angle + 20) * std::acos(-1)/180) * 20);

			int side2_x = int (p.x - std::cos ((angle - 20) * std::acos(-1)/180) * 20);
			int side2_y = int (p.y - std::sin ((angle - 20) * std::acos(-1)/180) * 20);

			arrow.add (p, Point(side1_x, side1_y));
			arrow.add (p, Point(side2_x, side2_y));
		}

		void draw_lines() const {
			arrow.draw_lines ();
		}
	}; // struct Arrow

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
			LineType lineType;
		protected :
			LineType getLineType() const {
				return lineType;
			}
		public :
			Binary_tree (int l, LineType t) : levels (l), lineType (t) {
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
						Arrow (Point(nodes[i].x, nodes[i].y - 5), 
								Point(nodes[(i - 1)/2].x + (i % 2 ? -5 : 5), nodes[(i - 1)/2].y),
									lineType).draw();
				}
			}

			vector<Point> getNodes () const {
				return nodes;
			}
	}; // class Binary_tree

	class Binary_tree_triangle : public Binary_tree {
		public :
			Binary_tree_triangle (int l, LineType t) : Binary_tree (l, t) { 
			}

			void draw_lines () const override {
				vector<Point> nodes = getNodes();
				for (int i = 0; i < nodes.size(); ++i) {
					Triangle current (nodes[i], 20, 20);
					current.draw_lines ();

					if (i > 0)  {
						Triangle parent (nodes[(i - 1)/2], 20, 20);
						Arrow (	i%2 ? parent.bottomLeft() : parent.bottomRight(), 
									current.top(), 
										Binary_tree::getLineType()).draw();
					}
				}
			}
	}; // class Binary_tree_triangle
} // namespace Graph_lib

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Binary tree");

	Graph_lib::Binary_tree_triangle t (5, Graph_lib::LineType::none);
	win.attach(t);

	win.wait_for_button();
	return 0;
}
