#include "e16-3_simple_window.h"

Simple_window::Simple_window (Graph_lib::Point xy, int w, int h, const string& title) :
								Window (xy, w,h, title),
									next_button (Graph_lib::Point (x_max() - 70,0), 70, 20, "Next", 
													[] (Graph_lib::Address, Graph_lib::Address pw) {
															Graph_lib::reference_to<Simple_window> (pw).next();}),
										button_pushed (false) {
	attach (next_button);

}

// call Simple_window::next() for the window located at pw
void Simple_window::cb_next (Graph_lib::Address, Graph_lib::Address pw) { 
	Graph_lib::reference_to<Simple_window> (pw).next();	
}

// modified venet loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
void Simple_window::wait_for_button() {
	while (!button_pushed)
		Fl::wait();

	
	button_pushed = false;
	Fl::redraw();

}

void Simple_window::next() {
	button_pushed = true;
}

int main (void) {
	Simple_window win (Graph_lib::Point(1920, 0), 1920, 1080, "Test of my own simple window");

	win.wait_for_button();
	return 0;
}
