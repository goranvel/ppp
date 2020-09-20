#include "../../Simple_window.h"

int main (void) {
   Graph_lib::Point t1 (2500, 500);

   Simple_window win (t1, 600, 400, "Canvas");

	Graph_lib::Circle c1 (Graph_lib::Point (100, 100), 80);
	c1.set_style (Graph_lib::Line_style (Graph_lib::Line_style::solid, 8));
	c1.set_color (Graph_lib::Color::blue);
	win.attach (c1);

	Graph_lib::Circle c2 (Graph_lib::Point (290, 100), 80);
	c2.set_style (Graph_lib::Line_style (Graph_lib::Line_style::solid, 8));
	win.attach (c2);

	Graph_lib::Circle c3 (Graph_lib::Point (480, 100), 80);
	c3.set_style (Graph_lib::Line_style (Graph_lib::Line_style::solid, 8));
	c3.set_color (Graph_lib::Color::red);
	win.attach (c3);


	Graph_lib::Circle c4 (Graph_lib::Point (190, 190), 80);
	c4.set_style (Graph_lib::Line_style (Graph_lib::Line_style::solid, 8));
	c4.set_color (Graph_lib::Color::yellow);
	win.attach (c4);

	Graph_lib::Circle c5 (Graph_lib::Point (380, 190), 80);
	c5.set_style (Graph_lib::Line_style (Graph_lib::Line_style::solid, 8));
	c5.set_color (Graph_lib::Color::green);
	win.attach (c5);


	win.set_label ("My Olympic Rings");
	win.wait_for_button();
	
	return 0;
}
