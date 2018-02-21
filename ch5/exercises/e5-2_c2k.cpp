#include <iostream>

double ctok (double c);

int main (void) {
	double c = 0;	// declare input variable

// std::cin >> d; // ?? d not declared should be c
	std::cin >> c; // remove temprature to input variable

// double k = ctok("c"); // remove '"' around c
	double k = ctok (c);		// convert temperature

//	std::Cout << k << '/n';	// '/n' should be '\n' and 'Cout' should be 'cout'
	std::cout << k << '\n';	// print out temperature;
	return 0;
}

double ctok (double c) {
//	int k = c + 273.15; // this should be double or we are loosing precission
	double k = c + 273.15;

//           v missing ';'
//	return int
//        ^^^ cannot return int
	return k;
}
