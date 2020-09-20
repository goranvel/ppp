#include "../../Simple_window.h"

int main (void) {
	Graph_lib::Point p (1500, 200);

	Simple_window win (p, 500, 500, "My house");

	Graph_lib::Rectangle frame		(Graph_lib::Point (100, 100), 150, 100);
	win.attach (frame);

	Graph_lib::Rectangle window	(Graph_lib::Point (180, 140), 40, 40);
	win.attach (window);

	Graph_lib::Rectangle door		(Graph_lib::Point (125, 140), 40, 60);
	win.attach (door);

	Graph_lib::Polygon roof;
	roof.add (Graph_lib::Point (85,	100));
	roof.add (Graph_lib::Point (265, 100));
	roof.add (Graph_lib::Point (175,	40));
	win.attach (roof);

	Graph_lib::Polygon chimney;
	chimney.add (Graph_lib::Point (100, 68));
	chimney.add (Graph_lib::Point (100, 88));
	chimney.add (Graph_lib::Point (120, 78));
	chimney.add (Graph_lib::Point (120, 68));
	win.attach (chimney);

	Graph_lib::Circle smoke1 (Graph_lib::Point (110, 50), 10);
	win.attach (smoke1);

	Graph_lib::Circle smoke2 (Graph_lib::Point (110, 30), 20);
	win.attach (smoke2);


	win.wait_for_button();

	return 0;
}
