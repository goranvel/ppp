#include "../../Simple_window.h"
#include "../../Graph.h"

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
	poly.set_style (Graph_lib::Line_style::dash);
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

	Graph_lib::Image pic (Graph_lib::Point(200, 250), "image.jpg");
	win.attach(pic);
//	myPic.move(100, 200); I am getting segfault due to FL_Image::draw()
//									image is constructed above with to suit this after move

	Graph_lib::Circle c (Graph_lib::Point (100, 100), 80);
	win.attach (c);

	Graph_lib::Ellipse e (Graph_lib::Point (100, 200), 75, 25);
	e.set_color (Graph_lib::Color::dark_red);
	win.attach (e);

	Graph_lib::Mark m (Graph_lib::Point (100, 200), '+');
	win.attach (m);

	ostringstream oss;
	oss <<	"screen size: " << Graph_lib::x_max() <<'*' << Graph_lib::y_max() <<
				", window size: " << win.x_max() << '*' << win.y_max();
	Graph_lib::Text sizes (Graph_lib::Point (100, 20), oss.str());
	win.attach (sizes);

	Graph_lib::Image pic2 (Graph_lib::Point(225, 225), "snow_cpp.gif");
	pic2.set_mask (Graph_lib::Point(40,40), 200, 150);
	win.attach(pic2);

	win.set_label ("My ...");
	win.wait_for_button();

	return 0;
}
