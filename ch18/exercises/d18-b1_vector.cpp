#include <iostream>
#include <vector>

void printVector (std::vector<int>);

int main (void) {
	std::vector<int> ga(10);
	ga[0] = 1;
	for (int i = 1; i < 10; ++i)
		ga[i] = ga[i - 1] << 1;

	printVector (ga);

	return 0;
}

void printVector (std::vector<int> v) {
	for (int i = 0; i < 10; i++)
		std::cout << v[i] << " ";

	std::cout << "\n";
}
