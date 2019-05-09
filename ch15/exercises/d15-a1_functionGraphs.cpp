#include "../../Simple_window.h"

int main (void) {
	Simple_window win (Graph_lib::Point(1920, 0), 1920, 1080, "Function Graphs");

	win.wait_for_button();
	
	return 0;
}
