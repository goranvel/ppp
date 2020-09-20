#include <iostream>

// ask user for a yes or no answer;
// retunrn 'b' to indicate a bad answer
char ask_user (std::string question);

// calculate area of rectangle;
//		return: -1 to indicate bad arguments
int area (int lenght, int width);

int main (void) {
	char ans = ask_user ("Am I an idiot");
	if (ans == 'b') {
		std::cout << "Bad input";
		return -1;
	}

	int a = area (-1, 2);
	if (a <= 0) {
		std::cout << "Area cannot be 0 or negative";
		return -2;
	}

	return 0;
}

int area (int lenght, int width) {
	if (lenght <= 0 || width <= 0)
		return -1;

	return lenght * width;
}

char ask_user (std::string question) {
	std::cout << question << "? (yes or no)\n";
	std::string answer = "";

	std::cin >> answer;

	if (answer == "yes" || answer == "y")
		return 'y';
	
	if (answer == "no" || answer == "n")
		return 'n';
	
	return 'b';
}
