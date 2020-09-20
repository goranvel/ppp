#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point t1 (500, 500);

	Simple_window win (t1, 600, 400, "Canvas");

	win.wait_for_button();

	return 0;
}
