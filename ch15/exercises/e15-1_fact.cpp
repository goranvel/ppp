#include <iostream>
#include <iomanip>

long double rec_fact (int n);
long double iter_fact (int n);

int main (void) {
	int n = 171;
	double rec = 0, iter = 0;
	int i = 0;
	for (; i <= n && rec == iter ; ++i) {
		rec = rec_fact(i);
		iter = iter_fact(i);
		std::cout << std::setw(3)	<< i;
		std::cout << std::setw(50)	<< std::setprecision(40) << rec << " ";
		std::cout << std::setw(50)	<< std::setprecision(40) << iter << "\n";

		if (rec != iter)
			break;
	}

	std::cout << std::setw(100)	<< std::setprecision(100) << rec << "\n";
	std::cout << std::setw(100)	<< std::setprecision(100) << iter << "\n";
	std::cout << std::setw(100)	<< std::setprecision(200) << iter - rec << "\n";

	return 0;
}

long double rec_fact (int n) {
	return n > 1 ? rec_fact (n - 1) * n : 1.0;
}

long double iter_fact (int n ) {
	long double fact = 1.0;
	for (; n > 1; --n) 
		fact *= n;

	return fact;
}
