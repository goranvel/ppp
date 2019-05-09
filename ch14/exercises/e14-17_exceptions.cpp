#include "../../Simple_window.h"
#include <stdexcept>

namespace Graph_lib {
	struct Box : public Shape {
		int width, height;
		double radius;
		Point point;
		std::string text;
		bool visited;

		Box (Graph_lib::Point p, std::string t) :
				point (p), width (t.size() * 9), height (24), radius (10), text (t), visited (false) {
			Shape::add (p); 
		}

		Point getTop () {
			return Point (point.x + width / 2, point.y);
		}

		Point getBottom () {
			return Point (point.x + width / 2, point.y + height);
		}

		int get_height () {
			return height;
		}

		void draw_lines () const {
			if (color().visibility()) {
				fl_color	( color().as_int());
				fl_line		( point.x + radius, point.y, point.x - radius + width, point.y );
				fl_line		( point.x + radius, point.y + height, point.x - radius + width, point.y + height );
				fl_line		( point.x, point.y + radius, point.x, point.y - radius + height );
				fl_line		( point.x + width, point.y + radius, point.x + width, point.y - radius + height );

				fl_draw		( text.c_str(), point.x + text.size(), point.y + height * 3/4 );	

				fl_arc		( point.x, point.y, radius * 2, radius * 2, 90, 180 );
				fl_arc		( point.x - radius * 2 + width, point.y,	radius * 2, radius * 2, 0, 90 );
				fl_arc		( point.x, point.y - radius * 2 + height, radius * 2, radius * 2, 180, 270 );
				fl_arc		( point.x - radius * 2 + width, point.y - radius * 2 + height, radius * 2, radius * 2, 270, 360 );
			}
		}

		void set_visited () {
			visited = true;
		}

		bool get_visited () {
			return visited;
		}

		std::ostream& operator<< (std::ostream& os) {
			return os << text;
		}
	}; // class Box

	class Connector : public Shape {
			Point start, end;
		public:
			Connector (Box &b1, Box &b2) : start(b1.getBottom()), end(b2.getTop()) {
				if (!b1.visited) {
					b1.set_visited();
					add (start);
				}
				Point mid = Point(start.x,	(start.y + end.y) / 2);
				add (mid);
				add (Point(end.x,	(start.y + end.y) / 2));
				add (end);

				if (b1.visited) {
					start = mid;
				}
			}

		void draw_lines () const {
			Shape::draw_lines();
		}
	}; // class connector
} // namespace Graph_lib

int main (void) {
	int win_w = 1920;
	int win_h = 1080;
	Simple_window win (Graph_lib::Point (1920, 0), win_w, win_h, "Exceptions");

	// first tear excetions
	Graph_lib::Box exception (Graph_lib::Point (win_w/2, 100), "Exception");
	win.attach(exception);

	// second tear exception
	int v_pos = win_h/4 - win_h/8;
	int h_pos = 200;

	Graph_lib::Box logic_error	(Graph_lib::Point(h_pos, v_pos + 100), "Logic Error");
	win.attach (logic_error);
	Graph_lib::Connector c00 (exception, logic_error);
	win.attach (c00);

	h_pos += 125;
	Graph_lib::Box bad_cast		(Graph_lib::Point(h_pos, v_pos + 100), "Bad Cast");
	win.attach (bad_cast);
	Graph_lib::Connector c01 (exception, bad_cast);
	win.attach (c01);

	h_pos += 100;
	Graph_lib::Box bad_weak_ptr	(Graph_lib::Point(h_pos, v_pos + 100), "Bad Weak Pointer (C++11)");
	win.attach (bad_weak_ptr);
	Graph_lib::Connector c02 (exception, bad_weak_ptr);
	win.attach (c02);

	h_pos += 250;
	Graph_lib::Box bad_typeid	(Graph_lib::Point(h_pos, v_pos + 100), "Bad Type ID");
	win.attach (bad_typeid);
	Graph_lib::Connector c03 (exception, bad_typeid);
	win.attach (c03);

	h_pos += 125;
	Graph_lib::Box bad_function_call (Graph_lib::Point(h_pos, v_pos + 100), "Bad Function Call (C++11)");
	win.attach (bad_function_call);
	Graph_lib::Connector c04 (exception, bad_function_call);
	win.attach (c04);

	h_pos += 250;
	Graph_lib::Box runtime_error (Graph_lib::Point(h_pos, v_pos + 100), "Runtime Error");
	win.attach (runtime_error);
	Graph_lib::Connector c05 (exception, runtime_error);
	win.attach (c05);

	h_pos += 150;
	Graph_lib::Box io_base_failure (Graph_lib::Point(h_pos, v_pos + 100), "IOS Base Failure (pre C++11)");
	win.attach (io_base_failure);
	Graph_lib::Connector c06 (exception, io_base_failure);
	win.attach (c06);

	h_pos += 250;
	Graph_lib::Box bad_exception (Graph_lib::Point(h_pos, v_pos + 100), "Bad Exception");
	win.attach (bad_exception);
	Graph_lib::Connector c07 (exception, bad_exception);
	win.attach (c07);

	h_pos += 150;
	Graph_lib::Box bad_alloc (Graph_lib::Point(h_pos, v_pos + 100), "Bad Alloc");
	win.attach (bad_alloc);
	Graph_lib::Connector c08 (exception, bad_alloc);
	win.attach (c08);

	// third level excecption
	v_pos += 100;
	h_pos = 0;
	Graph_lib::Box invalid_argument (Graph_lib::Point(h_pos, v_pos + 100), "Invaldi_argument");
	win.attach (invalid_argument);
	Graph_lib::Connector c0000 (logic_error, invalid_argument);
	win.attach (c0000);

	h_pos += 150;
	Graph_lib::Box domain_error (Graph_lib::Point(h_pos, v_pos + 100), "Domain Error");
	win.attach (domain_error);
	Graph_lib::Connector c0001 (logic_error, domain_error);
	win.attach (c0001);

	h_pos += 125;
	Graph_lib::Box out_of_range (Graph_lib::Point(h_pos, v_pos + 100), "Out of range");
	win.attach (out_of_range);
	Graph_lib::Connector c0002 (logic_error, out_of_range);
	win.attach (c0002);

	h_pos += 125;
	Graph_lib::Box future_error (Graph_lib::Point(h_pos, v_pos + 100), "Future Error (C++11)");
	win.attach (future_error);
	Graph_lib::Connector c0003 (logic_error, future_error);
	win.attach (c0003);

	h_pos += 300;
	Graph_lib::Box range_error (Graph_lib::Point(h_pos, v_pos + 100), "Range Error");
	win.attach (range_error);
	Graph_lib::Connector c0200 (runtime_error, range_error);
	win.attach (c0200);

	h_pos += 125;
	Graph_lib::Box overflow_error (Graph_lib::Point(h_pos, v_pos + 100), "Overflow Error");
	win.attach (overflow_error);
	Graph_lib::Connector c0201 (runtime_error, overflow_error);
	win.attach (c0201);

	h_pos += 150;
	Graph_lib::Box underflow_error (Graph_lib::Point(h_pos, v_pos + 100), "Underflow Error");
	win.attach (underflow_error);
	Graph_lib::Connector c0202 (runtime_error, underflow_error);
	win.attach (c0202);

	h_pos += 150;
	Graph_lib::Box regex_error (Graph_lib::Point(h_pos, v_pos + 100), "Regex Error (C++11)");
	win.attach (regex_error);
	Graph_lib::Connector c0203 (runtime_error, regex_error);
	win.attach (c0203);

	h_pos += 175;
	Graph_lib::Box system_error (Graph_lib::Point(h_pos, v_pos + 100), "System Error (C++11)");
	win.attach (system_error);
	Graph_lib::Connector c0204 (runtime_error, system_error);
	win.attach (c0204);

	h_pos += 214;
	Graph_lib::Box bad_array_new_lenght (Graph_lib::Point(h_pos, v_pos + 100), "Bad Array New Lenght (C++11)");
	win.attach (bad_array_new_lenght);
	Graph_lib::Connector c0205 (bad_alloc, bad_array_new_lenght);
	win.attach (c0205);

	// third level excecption
	v_pos += 100;
	h_pos = 1282;
	Graph_lib::Box ios_base_failure_11 (Graph_lib::Point(h_pos, v_pos + 100), "IOS Base Failure (C++11)");
	win.attach (ios_base_failure_11);
	Graph_lib::Connector c020400 (system_error, ios_base_failure_11);
	win.attach (c020400);

	win.wait_for_button();
	return 0;
}
