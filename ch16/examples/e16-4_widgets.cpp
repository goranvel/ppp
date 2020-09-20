#include "e16-4_widgets.h"

namespace Graph_lib {
	My_Widget::My_Widget (Point xy, int w, int h, const std::string& label, Callback cb) {
		
	}

	void My_Widget::move (int dx, int dy) {
	}

	void My_Widget::hide () {
	}

	void My_Widget::show () {
	}

	My_Button::My_Button (Point xy, int w, int h, const std::string& label, Callback cb) :
							Widget (xy, w, h, label, cb) {
		
	}

	void My_Button::attach (Window&) {
	}

	void My_Button::hide () {
	}

	My_In_box::My_In_box (Point xy, int w, int h, const std::string& s) : 
							Widget (xy, w, h, s, 0) {
	}

	int My_In_box::get_int () {
		return 0;	
	}

	std::string My_In_box::get_string() {
		return "";
	}

	My_Menu::My_Menu (Point xy, int w, int h, Kind kk, const std::string& label) :
								Widget (xy, w, h, label, 0) {
	}

	void My_Menu::show () { // whow all buttons
		for (int i= 0; i < selection.size(); ++i) 
			selection[i].show();
	}

	void My_Menu::hide () {
	}

	int My_Menu::attach (Button& b) {
	}

	int My_Menu::attach (Button* b) {
	}

	void My_Menu::move (int dx, int dy) {
	}

	void My_Menu::attach (Window& win) {
	}
} // namespace Graph_lib

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
	return 0; }
