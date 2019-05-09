#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point p (1600, 100);

	Simple_window win (p, 400, 400, "Picture");

	Graph_lib::Image pic (Graph_lib::Point(1, 1), "mimi.jpg");
	win.attach (pic);

	Graph_lib::Text txt (Graph_lib::Point (15, 15), "Little witch");
	txt.set_color (Graph_lib::Color::yellow);
	win.attach (txt);

	win.wait_for_button();
	return 0;
}
