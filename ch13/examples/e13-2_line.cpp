#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point x {100, 100};

	Simple_window win (x, 600, 400, "two line");

	Graph_lib::Line horizontal (x, Graph_lib::Point (200, 100));
	Graph_lib::Line vertical	(Graph_lib::Point (150, 50), Graph_lib::Point (150, 150));

	win.attach	(horizontal);
	win.attach	(vertical);

	win.wait_for_button();

	return 0;
}
