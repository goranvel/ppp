#include <iostream>
#include <vector>

void print (std::string name, std::vector<int>& v);

int main (void) {
	std::vector<int> v (10, 1);
	print ("v", v);
	return 0;
}

void print (std::string name, std::vector<int>& v) {
	std::cout << "Vector '" << name << "' has following elements:\n";

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << (i + 1 == v.size() ? "" : " ");

	std::cout << "\n";
}
