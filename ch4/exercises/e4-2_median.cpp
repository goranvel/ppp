#include <iostream>
#include <vector>
#include <algorithm>

int main (void) {
	std::vector<double> vals;

	for (double num; std::cin >> num;)
		vals.push_back(num);

	std::sort (vals.begin(), vals.end());
	std::cout << "Mean is " << ((vals.size() % 2) ? vals.at(vals.size()/2) :
		vals.at(vals.size ()/2) + vals.at(vals.size ()/2 - 1))/2;

	return 0;
}
