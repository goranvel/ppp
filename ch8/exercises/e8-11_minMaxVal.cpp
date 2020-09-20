#include <iostream>
#include <vector>

struct MinMax {
	int min;
	int max;
};
struct MinMax min_max (std::vector<int> v);

int main (void) {
	std::vector<int> v;
	v.push_back (1);
	v.push_back (3);
	v.push_back (5);
	v.push_back (2);

	std::cout << min_max(v).min << " " << min_max(v).max << "\n";
	return 0;
}

struct MinMax min_max (std::vector<int> v) {
	int max = 0, min = -1;
	for (int i = 0; i < v.size(); ++i) {
		if (max < v[i])
			max = v[i];
		if (min > v[i] || min == -1)
			min = v[i];
	}
	struct MinMax m = {min, max};
	return m;
}
