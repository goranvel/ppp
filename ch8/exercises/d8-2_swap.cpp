#include <iostream>

void swap_v (int a, int b);
void swap_r (int& a, int& b);
void swap_c (const int a, const int b);
void swap_cr (const int& a, const int& b);

int main (void) {
	swap_v (7, 9);
	// swap_r (7, 9); // non constant number
	swap_c (7, 9); 
	swap_cr (7, 9);
	std::cout << "\n";


	int x = 7, y = 9;
	std::cout << "\t\t" << x << " " << y << "\n";
	swap_v (x, y);
	std::cout << "after v:\t" << x << " " << y << "\n";
	swap_r (x, y);
	std::cout << "after r:\t" << x << " " << y << "\n";
	swap_c (x, y); 
	std::cout << "after c:\t" << x << " " << y << "\n";
	swap_cr (x, y);
	std::cout << "after rc:\t" << x << " " << y << "\n";
	std::cout << "\n";

	const int cx = 7, cy = 9;
	std::cout << "\t\t" << cx << " " << cy << "\n";
	swap_v (cx, cy);
	std::cout << "after v:\t" << cx << " " << cy << "\n";
//	swap_r (cx, cy); // constant to non-constant reference is ILLEGALL
	std::cout << "after r:\t" << cx << " " << cy << "\n";
	swap_c (cx, cy); 
	std::cout << "after c:\t" << cx << " " << cy << "\n";
	swap_cr (cx, cy);
	std::cout << "\n";

	double dx = 7.8, dy = 9.5;
	std::cout << "\t\t" << dx << " " << dy << "\n";
	swap_v (dx, dy);
	std::cout << "after v:\t" << dx << " " << dy << "\n";
//	swap_r (dx, dy);	// double do non-constant reference is ILLEGALL
	std::cout << "after r:\t" << dx << " " << dy << "\n";
	swap_c (dx, dy); 
	std::cout << "after c:\t" << dx << " " << dy << "\n";
	swap_cr (dx, dy);
	std::cout << "after rc:\t" << dx << " " << dy << "\n";
}

void swap_v (int a, int b) {
	std::cout << "-- " << a  << " "<< b << "\n";
	int temp = a;
	a = b;
	b = temp;

	std::cout << "v:\t\t" << a << " " << b << "\n";
}

void swap_r (int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

	std::cout << "r:\t\t" << a << " " << b << "\n";
}

void swap_c (const int a, const int b) {
	int temp = a;
//	a = b;		// compile time error cannot change vealue  ILLEGAL
//	b = temp;	// compile time error cannot change vealue 
	std::cout << "c:\t\t" << a << " " << b << "\n";
}

void swap_cr (const int& a, const int& b) {
	int temp = a;
//	a = b;		// compile time error cannot change vealue 
//	b = temp;	// compile time error cannot change vealue 

	std::cout << "cr:\t\t" << a << " " << b << "\n";
}
