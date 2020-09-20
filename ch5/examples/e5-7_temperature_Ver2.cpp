#include <iostream>

int main (void) {
	double sum = 0;
	double high_temp = -1000;
	double low_temp = 1000;
	int no_of_temps = 0;


	for (double temp; std::cin >> temp;) { // read and put tinto temps
		++no_of_temps;			// count temperatures

		if (temp > high_temp)
			high_temp = temp;		// find high
		if (temp < low_temp)
			low_temp	 = temp;
		
		sum += temp;	// compute sum
	}

	std::cout << "High temperature: "		<< high_temp	<< '\n';
	std::cout << "Low temperature: "			<< low_temp		<< '\n';
	std::cout << "Average tempreature: "	<< sum/no_of_temps << '\n';

	return 0;
}
