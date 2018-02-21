#include <iostream>
#include <vector>		// include because of vectors
#include <algorithm>	// included because of sort

// read some temperatures into a vector
int main (void) {
	std::vector<double> temps;	// temperatures

	for (double temp; std::cin >> temp;)	// read into temp
		temps.push_back (temp);			// put temp into vector

	// compute sum temperatuere
	double sum = 0;
	for (double temp : temps)
		sum += temp;

	// prints average
	std::cout << "Average temperture: " << sum / temps.size() << "\n";

	std::sort (temps.begin(), temps.end()); // sort the temps

	// compute mean and print it out
	std::cout << "Median Temperature: " << temps[temps.size()/2] << '\n';

	return 0;
}
