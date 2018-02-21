#include <iostream>
#include <vector>

int maxv (std::vector<int> v);

int main (void) {
	std::vector<int> v;
	v.push_back (1);
	v.push_back (3);
	v.push_back (5);
	v.push_back (0);

	std::cout << maxv(v) << "\n";
	return 0;
}

int maxv (std::vector<int> v) {
	int max = 0;
	for (int i = 0; i < v.size(); ++i)
		if (max < v[i])
			max = v[i];

	return max;
}
