#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> split (std::string s, const std::string& w);

int main (void) {
	std::vector<std::string> v = split ("alksfjds,sdfsdaf;lkds", ",;");

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << "\n";

	return 0;
}

std::vector<std::string> split (std::string s, const std::string& w) {
	std::vector<std::string> v;
	
	for (int i = 0; i < s.size(); ++i)
		for (int j = 0; j < w.size(); ++j)
			if (s[i] == w[j] && (s[i - 1] != ' ' || s[i + 1] != ' '))
				s[i] = ' ';

	std::stringstream ss (s);

	std::string in;
	while (ss >> in) 
		v.push_back (in);

	return v;
}
