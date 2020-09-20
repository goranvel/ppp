#include <iostream>

void sizes ();
int main (void) {
	sizes();	
	return 0;
}

void sizes() {
	std::cout << "int\t"		<< sizeof(int)		<< "\n";
	std::cout << "int*\t"		<< sizeof(int*)		<< "\n";
	std::cout << "char\t"		<< sizeof(char)		<< "\n";
	std::cout << "char*\t"		<< sizeof(char*)	<< "\n";
	std::cout << "bool\t"		<< sizeof(bool)		<< "\n";
	std::cout << "bool*\t"		<< sizeof(bool*)	<< "\n";
	std::cout << "double\t"		<< sizeof(double)	<< "\n";
	std::cout << "double*\t"	<< sizeof(double*)	<< "\n";
}
