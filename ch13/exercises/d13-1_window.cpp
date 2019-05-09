#include "../../Simple_window.h"

class Grid {
		Graph_lib::Lines lines;

	public :
		Grid (int x, int y, int w, int h);

		Graph_lib::Lines getLines() {
			return lines;
		}
};

Grid::Grid (int x, int y, int w, int h) {
	lines = Graph_lib::Lines ();
	for (int i = 0, points = 0; i < x; ++i, points += w)
		lines.add(Graph_lib::Point (points, 0), Graph_lib::Point (points, 800));

	for (int i = 0, points = 0; i < x; ++i, points += h)
		lines.add(Graph_lib::Point (points, 0), Graph_lib::Point (points, 800));
};

int main (void) {
	Graph_lib::Point p (1900, 0);

	Simple_window win (p, 800, 1000, "CH 13 Drill 1");

	Grid grid (8, 8, 100, 100);

	win.attach (grid.getLines());
	win.wait_for_button();
	return 0;
}
