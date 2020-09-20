#include <iostream>
#include <vector>

std::vector<std::string> split (const std::string& s) {
	std::vector<std::string> v;
	std::stringstream ss (s);

	std::string in;
	while (ss >> in) 
		v.push_back (in);

	return v;
}

int main (void) {
	return 0;
}
