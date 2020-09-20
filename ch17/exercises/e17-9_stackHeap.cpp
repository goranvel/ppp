#include <iostream>

int main (void) {
	char ch1 = 0;
	char ch2 = 0;
	char ch3 = 0;

	std::cout << "Address on stack:\n"	<< long(&ch1) << " " 
										<< long(&ch2) << " " 
										<< long(&ch3) << "\n";

	std::cout << (ch2 > ch1 && ch3 > ch2 ? "Stack grows up.\n" : "Stack grows down") << "\n\n";

	char *chp1 = new char();
	char *chp2 = new char();
	char *chp3 = new char();

	std::cout << "Address on stack:\n"	<< long(chp1) << " " 
										<< long(chp2) << " " 
										<< long(chp3) << "\n";

	std::cout << (chp2 > chp1 && chp3 > chp2 ? "Heap grows up.\n" : "Heap grows down") << "\n";


	return 0;
}
