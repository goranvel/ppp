#include "../../Simple_window.h"

class Controller {
		bool isOn;
		int level;
	protected:
		Controller () : isOn(false), level (0) {
		}
		Controller (bool on, int l) : isOn (on), level (l) {
		}
	public:
		virtual void on() {
			isOn = true;
		}

		virtual void off() {
			isOn = false;
		}

		virtual void set_level(int l) {
			level = l;
		}

		virtual void show () {
			std::cout << "Controler is " << (isOn ? "on" : "off") << " level is " << level << ".\n";
		}

		bool is_on() {
			return isOn;
		}

		int get_level() {
			return level;
		}
};

class Controller_test : Controller {
	public :
		Controller_test () : Controller () {
		}

		Controller_test (bool on, int l) : Controller (on, l) {
		}
	
		void on () {
			Controller::on();
		}

		void off () {
			Controller::off();
		}

		void set_level (int l) {
			Controller::set_level(l);
		}

		void show () {
			Controller::show();
		}
};

class Shape_controller : Controller {
		Graph_lib::Shape& shape;
	public :
		Shape_controller (Graph_lib::Shape &s) : shape(s) {
		}

		void on () {
			Controller::on ();
			shape.set_color (Graph_lib::Color::visible);
		}

		void off () {
			Controller::off ();
			shape.set_color (Graph_lib::Color::invisible);
		}

		void set_level (int l) {
			Controller::set_level (l);
			shape.set_style (Graph_lib::Line_style (Graph_lib::Line_style::solid, l));
		}

		void show () override {
			std::cout << "Shape is " << (Controller::is_on() ? "on" : "off") << " level is " << get_level() << ".\n";
		}
};


int main (void) {
	Simple_window win (Graph_lib::Point (1920, 0), 500, 500, "Controller");
	Controller_test t;
	t.on();
	t.set_level(15);
	t.show();
	t.off();
	t.set_level(45);
	t.show();

	Graph_lib::Circle c (Graph_lib::Point (100, 100), 100);
	Shape_controller s(c);
	s.off();
	s.show();
	win.attach (c);
	win.wait_for_button();
	s.on ();
	s.set_level(50);
	s.show();
	win.wait_for_button();
	return 0;
}
