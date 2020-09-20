#include <iostream>
#include <cctype>

void clasifyChar (char c);

int main (void) {
	std::string input;

	while (std::cin >> input)
		for (int i = 0; i < input.size(); ++i)
			clasifyChar (input[i]);

	return 0;
}
	
void clasifyChar (char c) {
	std::cout << c;
	if (std::isspace(c))
		std::cout << " a white space character\n";
	if (std::isalpha(c))
		std::cout << " ASCII character";
	if (std::isdigit(c))
		std::cout << " digit";
	if (std::isxdigit(c))
		std::cout << " hex digit";
	if (std::isupper(c))
		std::cout << " uppercase letter";
	if (std::islower(c))
		std::cout << " lowercase letter";
	if (std::isalnum(c))
		std::cout << " letter or digit";
	if (std::iscntrl(c))
		std::cout << " control character";
	if (std::ispunct(c))
		std::cout << " punctuation character";
	if (std::isprint(c))
		std::cout << " printable character";
	if (std::isgraph(c))
		std::cout << " graphic character";
	std::cout << "\n";
}
