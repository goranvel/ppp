#include <iostream>
#include <vector>

void printVector (std::vector<int>);
void f(std::vector<int>);

int main (void) {
	std::vector<int> gv;
	gv.push_back(1);
	for (int i = 1; i < 10; ++i)
		gv.push_back(gv[i - 1] << 1);

	printVector (gv);
	
	f (gv);
	return 0;
}

void printVector (std::vector<int> v) {
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";

	std::cout << "\n";
}

void f (std::vector<int> v) {
	std::vector<int> lv;

	for (int i = 0; i < v.size(); ++i)
		lv.push_back(v[i]);

	printVector (lv);

	std::vector<int> iv (v);

	printVector (iv);
}
