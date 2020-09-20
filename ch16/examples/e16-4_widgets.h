#include "../../GUI.h"

namespace Graph_lib {
	// Widghet is a handle to an Fl_widget - it is "not" an Fl_widget
	class My_Widget {
		public:
			My_Widget (Point xy, int w, int h, const std::string& s, Callback ch);

			virtual void move (int dx, int dy);
			virtual void hide ();
			virtual void show ();
			virtual void attach (Window &) = 0;

			Point loc;
			int width;
			int height;
			std::string label;
			Callback do_it;
		private:
			Window* own;	// every Widget belongs to a Window
			Fl_Widget* pw;	// connection to the FLK Widget
	};

	struct My_Button : public Widget {
			My_Button (Point xy, int ww, int hh, const std::string& s, Callback cb);
			void attach (Window&);

			void hide ();
	};

	struct My_In_box : Widget {
		My_In_box (Point xy, int w, int h, const std::string& s);

		int get_int ();
		std::string get_string();

		void attah (Window& win);
	};

	struct My_Out_box : Widget {
		My_Out_box (Point xy, int w, int h, const std::string& s);

		void put (int);
		void put (const string&);

		void attah (Window& win);
	};

	struct My_Menu : Widget {
		enum Kind {
			horizontal,
			vertical
		};
		My_Menu (Point xy, int w, int h, Kind kk, const std::string& label);

		Vector_ref<Button> selection;
		Kind k;
		int offset;
		int attach (Button &b);
		int attach (Button *b);

		void show ();

		void hide ();	// hide all buttons
		void move (int dx, int dy);	// move all buttons
		void attach (Window& win);	// attach all buttons to Window win
	};
}

struct Simple_window:Graph_lib::Window {
		Simple_window (Graph_lib::Point xy, int w, int h, const string& title);

		void wait_for_button(); // simple event loop
	
	private:
		Graph_lib::Button next_button;	// the "Next" button
		bool button_pushed;				// implementation detail

		static void cb_next (Graph_lib::Address, Graph_lib::Address);		// callback for next_button

		void next();	// action to be done when next_button is pressed
};
