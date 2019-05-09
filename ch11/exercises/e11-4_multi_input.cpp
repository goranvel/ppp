#include <iostream>
#include <vector>
#include <ctype.h>
#include <sstream>

enum class inType {dec, hex, oct};

int main (void) {
	std::cin.unsetf (std::ios::dec);
	std::cin.unsetf (std::ios::oct);
	std::cin.unsetf (std::ios::hex);
	std::cout << std::showbase;

	std::cout << "Enter any number (decimal, hex, or octal) folowed by white space.\n";
	std::cout << "\t\tpres CTL + D (CTL + Z  on Windows) to quit.\n";

	int in = 0;
	std::string input;
	inType type = inType::dec;

	while (1) {
		std::cin >> input;
		if (std::cin.eof())
			break;

		if (input[0] == '0')
			if (input[1] == 'x')
				type = inType::hex;
			else if (isdigit (input[1])) 
				type = inType::oct;
			else
				type = inType::dec;
		
		std::istringstream iss (input);
		iss.unsetf (std::ios::dec);

		iss >> in;

		std::cout << (type == inType::hex ? std::hex : type == inType::oct ? std::oct : std::dec) 
						<< in << 
						(type == inType::hex ? " hexadecimal" : type == inType::oct ? " octal" : " decimal") 
						<< " covnerts to " << std::dec << in << "\n";
	}

	return 0;
}
