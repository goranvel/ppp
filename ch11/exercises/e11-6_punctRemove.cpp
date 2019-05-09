#include <iostream>
#include <cctype>

void punctRemove (char& c);

int main (void) {
	std::string input;

	while (std::cin >> input) {
		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == '-' && input [i - 1] && input [i + 1]) 
				continue;

			punctRemove (input[i]);
		}

		std::cout << input << "\n";
	}

	return 0;
}
	
void punctRemove (char& c) {
	if (c != '\'' && std::ispunct(c))
		c = ' ';
}
