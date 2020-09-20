#include "../../Simple_window.h"

void f (Simple_window& w) {
	Graph_lib::Rectangle r (Graph_lib::Point (100, 200), 100, 100);

	w.attach(r);

}

int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 400, 400, "Test");

	f(win);

	w.wait_for_button();
	return 0;
}
