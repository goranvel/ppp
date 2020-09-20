#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main (void) {
	std::string fname;
	std::cout << "Please enter a file name: ";
	std::cin >> fname;
	std::ifstream ifs (fname.c_str());

	std::cout << "Please enter a file name: ";
	std::cin >> fname;
	std::ofstream ofs (fname.c_str());

	std::vector<int> numbers;

	int num, cnt;
	while (ifs >> num)
		numbers.push_back(num);

	std::sort (numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); ++i) {
		ofs << numbers[i];
		if (numbers[i] == numbers[i+1]) {
			cnt = 1;
			while (numbers[i] == numbers[i+1]) {
				++cnt;
				++i;
			}

			ofs << " " << cnt;
		}
		ofs << "\n";
	}
	return 0;
}
