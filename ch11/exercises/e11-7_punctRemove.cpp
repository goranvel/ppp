#include <iostream>
#include <cctype>

int main (void) {
	std::string input;

	while (std::cin >> input) {
		//	std::cout << input << "--\n";

		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == '-' && input[i-1] != ' ' && input[i+1] != ' ')
				continue;
		
			if (input[i] == '\'') {
				if (input[i+1] == 't' && input[i-1] == 'n') { 
					input[i-1] = ' ';
					input[i] = 'n';
					input[i + 1] = 'o';
					input += 't';
				}

				if (input[i+1] == 's') {
					input [i] = ' ';
					input [i+1] = 'i';
					input += 's';
				}

				if (input[i+1] == 'd') {
					input [i] = ' ';
					input [i+1] = 'd';
					input += "id";
				}
				
				if (input[i+1] == 'm') {
					input [i] = ' ';
					input [i+1] = 'a';
					input += "m";
				}

				if (input[i+1] == 'r' && input[i+2] == 'e') {
					input [i] = ' ';
					input [i+1] = 'a';
					input [i+2] = 'r';
					input += "e";
				}

				if (input[i+1] == 'l' && input[i+2] == 'l') {
					input [i] = ' ';
					input [i+1] = 'w';
					input [i+2] = 'i';
					input += "ll";
				}

			} else if (std::ispunct(input[i]))
				input[i] = ' ';
		}
		std::cout << input << " ";
	}

	return 0;
}
