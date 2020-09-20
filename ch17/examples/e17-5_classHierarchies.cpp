#include <iostream> 

class top {
	public :
		top () {
			std::cout << "Top was constructed";
		}

		~top () {
			std::cout << "Top was destructed";
		}
};

class bottom : top {
		std::string* s;
	public :
		bottom () : s (new std::string) {
			std::cout << "Bottom was constructed";
		}

		~bottom () {
			std::cout << "bottom was destructed";
		}
};

int main (void) {
//	bottom *b = new bottom();
	int toto ();
	toto();
	for (int i = 10000; i; --i);
	return 0;
}

int toto () {
	bottom* t = new bottom{};
}
