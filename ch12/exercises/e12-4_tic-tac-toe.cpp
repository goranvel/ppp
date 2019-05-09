#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point t1 (2500, 500);

	Simple_window win (t1, 500, 500, "Canvas");

	Graph_lib::Rectangle cube11 (Graph_lib::Point (100, 100), 100, 100);
	cube11.set_color (Graph_lib::Color::red);
	cube11.set_fill_color(Graph_lib::Color::red);
	win.attach(cube11);

 	Graph_lib::Rectangle cube12 (Graph_lib::Point (200, 100), 100, 100);
	cube12.set_color (Graph_lib::Color::white);
	cube12.set_fill_color(Graph_lib::Color::white);
	win.attach(cube12);

 	Graph_lib::Rectangle cube13 (Graph_lib::Point (300, 100), 100, 100);
	cube13.set_color (Graph_lib::Color::red);
	cube13.set_fill_color(Graph_lib::Color::red);
	win.attach(cube13);


	Graph_lib::Rectangle cube21 (Graph_lib::Point (100, 200), 100, 100);
	cube21.set_color (Graph_lib::Color::white);
	cube21.set_fill_color(Graph_lib::Color::white);
	win.attach(cube21);

 	Graph_lib::Rectangle cube22 (Graph_lib::Point (200, 200), 100, 100);
	cube22.set_color (Graph_lib::Color::red);
	cube22.set_fill_color(Graph_lib::Color::red);
	win.attach(cube22);

 	Graph_lib::Rectangle cube23 (Graph_lib::Point (300, 200), 100, 100);
	cube23.set_color (Graph_lib::Color::red);
	cube23.set_fill_color(Graph_lib::Color::white);
	win.attach(cube23);


	Graph_lib::Rectangle cube31 (Graph_lib::Point (100, 300), 100, 100);
	cube31.set_color (Graph_lib::Color::red);
	cube31.set_fill_color(Graph_lib::Color::red);
	win.attach(cube31);

 	Graph_lib::Rectangle cube32 (Graph_lib::Point (200, 300), 100, 100);
	cube32.set_color (Graph_lib::Color::white);
	cube32.set_fill_color(Graph_lib::Color::white);
	win.attach(cube32);

 	Graph_lib::Rectangle cube33 (Graph_lib::Point (300, 300), 100, 100);
	cube33.set_color (Graph_lib::Color::red);
	cube33.set_fill_color(Graph_lib::Color::red);
	win.attach(cube33);


	win.set_label ("My Tic-Tac-Toe");
	win.wait_for_button();

	return 0;
}
