#include <iostream>

int main (void) {
	std::cout	<< std::hex << 1234 << " in hex " 
					<< std::oct << 1234 << " in octal " 
					<< 1234 << " in octal once again ";
	std::cout	<< 1234 << " and again octal`" 
					<< std::dec << 1234 << "\n";

	return 0;
}
