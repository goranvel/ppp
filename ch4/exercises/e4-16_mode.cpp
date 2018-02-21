#include <iostream>
#include <vector>
#include <algorithm>

int main (void) {
	std::vector<int> numbers;
	int num = 0, mode = 0, modeCnt = 1;

	while (std::cin >> num)
		numbers.push_back (num);

	std::sort (numbers.begin(), numbers.end());

	for (int i = 1, cnt = 1; i < numbers.size(); ++i) {
		if (numbers.at(i) == numbers.at(i - 1))
			++cnt;
		else
			cnt = 1;

		if (cnt > modeCnt) {
			mode = numbers.at(i);
			modeCnt = cnt;
		}
	}	

	std::cout << "Mode is " << mode << " with " << modeCnt << " occurances";

	return 0;
}
