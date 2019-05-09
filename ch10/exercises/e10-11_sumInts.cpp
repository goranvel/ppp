#include <iostream>
#include <fstream>

int main (void) {
	int n = 0;
	int sum = 0;
	std::string fname;
	std::cout << "Please enter input file name.";
	std::cin >> fname;

	std::ifstream ifs (fname.c_str());
	while (ifs) {
		ifs >> n;
		char ch;

		// check if digit is not followed by space or another digit
		if (ifs.get(ch) && !isdigit (ch) && 
				ch != ' ' && ch != '\t' && ch != '\n') 
			continue;
		else 
			ifs.unget();

		if (ifs.eof())
			break;
		if (ifs.fail()) {
			ifs.clear();
			for (	char ch; ifs.get(ch) && 
						ch != ' ' && ch != '\t' && ch != '\n'; );

			continue;			
		}
	
		sum += n;
	}
	std::cout << sum;
	return 0;
}
