#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point p (1600, 100);
	
	Simple_window win (p, 600, 400, "My window");

	Graph_lib::Rectangle rec (Graph_lib::Point (100, 100), 300, 200);
	rec.set_color (Graph_lib::Color::red);
	rec.set_style (Graph_lib::Line_style (Graph_lib::Line_style::solid, 6));
	win.attach (rec);

	win.wait_for_button();
	return 0;
}
