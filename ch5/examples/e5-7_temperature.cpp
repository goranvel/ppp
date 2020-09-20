#include <iostream>
#include <vector>

int main (void) {
	std::vector<double> temps;			// temeratures

	for (double temp; std::cin >> temp;)	// read and put tinto temps
		temps.push_back (temp);

	double sum = 0;
	double high_temp = 0;
	double low_temp = 0;

	for (int x : temps) {
		if (x > high_temp)
			high_temp = x;		// find high
		if (x < low_temp)
			low_temp	 = x;
		
		sum += x;	// compute sum
	}

	std::cout << "High temperature: "		<< high_temp	<< '\n';
	std::cout << "Low temperature: "			<< low_temp		<< '\n';
	std::cout << "Average tempreature: "	<< sum/temps.size() << '\n';

	return 0;
}
