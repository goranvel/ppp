#include <iostream>

int main (void) {
	char input;
	char *string, *oldString;
	int i = 0;
	while (std::cin >> input && input != '!') {
		oldString = string;
		string = new char[i + 2];
		for (int j = 0; j < i; string[j] = oldString[j], ++j);
		string[i] = input;
		string[++i] = '\0';
		delete[] oldString;
	}

	std::cout << string;
	delete[] string;
	return 0;
}
