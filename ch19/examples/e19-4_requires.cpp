#include <iostream>
#include <string>

class vehicle {
		std::string name;
	protected :
		vehicle (std::string n) : name (n) {
		}

	public:
		void print () {
			std::cout << name << "\n";
		}
};

class car : public vehicle {
	public:
		car () : vehicle ("car") {
		}
};

class train : public vehicle {
	public:
		train () : vehicle("train") {
		}
};

template <typename T> 
void printIt (T veh) {
	veh.print();
}

int main (void) {
	// printIt (car());
	printIt (train());
	car c();
	// c.print();
	return 0;
}
