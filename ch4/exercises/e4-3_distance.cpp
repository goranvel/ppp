#include <iostream>
#include <vector>
#include <algorithm>

int main (void) {
	std::vector<double> distances;
	double min = (unsigned long) ~0, max = 0, sum = 0;

	for (double d; std::cin >> d; ) {
		distances.push_back (d);

		if (min > d)
			min = d;

		if (max < d)
			max = d;

		sum += d;
	}

	std::sort (distances.begin(), distances.end());

	std::cout << "Maximum is:\t"	<< min	<< "\n";
	std::cout << "Minimum is:\t"	<< max	<< "\n";
	std::cout << "Sum is\t"			<< sum	<< "\n";
	std::cout << "Mean is\t"		<< sum / distances.size()	<< "\n";
		
	return 0;
}
