#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point t1 (2500, 500);

	Simple_window win (t1, 600, 400, "Canvas");

	Graph_lib::Axis xAxis (Graph_lib::Axis::x, Graph_lib::Point(20, 300), 200, 10, "x");
	win.attach (xAxis);

	Graph_lib::Axis yAxis (Graph_lib::Axis::y, Graph_lib::Point(20, 300), 280, 10, "y");
	win.attach (yAxis);

	Graph_lib::Function sine (std::sin, 0, 100, Graph_lib::Point(20, 150), 1000, 50, 50);
	sine.set_color (Graph_lib::Color::blue);
	win.attach (sine);

	Graph_lib::Polygon poly;
	poly.add (Graph_lib::Point (300, 200));
	poly.add (Graph_lib::Point (350, 100));
	poly.add (Graph_lib::Point (400, 200));
	poly.set_color (Graph_lib::Color::red);
	poly.set_style(Graph_lib::Line_style::dash);
	win.attach (poly);

	Graph_lib::Rectangle rect (Graph_lib::Point (200, 200), 100, 50);
	win.attach(rect);

	Graph_lib::Closed_polyline poly_rect;
	poly_rect.add (Graph_lib::Point (100, 50));
	poly_rect.add (Graph_lib::Point (200, 50));
	poly_rect.add (Graph_lib::Point (200, 100));
	poly_rect.add (Graph_lib::Point (100, 100));
	// added point
	poly_rect.add (Graph_lib::Point (50, 75));
	win.attach (poly_rect);

	rect.set_fill_color (Graph_lib::Color::yellow);

	poly.set_style (Graph_lib::Line_style (Graph_lib::Line_style::dash, 4));

	poly_rect.set_style (Graph_lib::Line_style (Graph_lib::Line_style::dash, 2));
	poly_rect.set_fill_color (Graph_lib::Color::green);

	Graph_lib::Text text (Graph_lib::Point (150, 150), "Hello, graphical world!!");
	text.set_font (Graph_lib::Font::times_bold);
	text.set_font_size(20);
	win.attach(text);

	win.set_label ("My text");
	win.wait_for_button();

	return 0;
}
