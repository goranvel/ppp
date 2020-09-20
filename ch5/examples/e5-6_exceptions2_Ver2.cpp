#include <iostream>
#include <vector>
#include <stdexcept>

int main (void)  {
//try {
	std::vector<int> v;		// a vector fo ints
	
	for (int x; std::cin >> x;)
		v.push_back (x);		// set values
	
	for (int i = 0; i <= v.size() + 10000; ++i)		// print values
		// will not work without Stroustrup headers
//		std::cout << "v[" << i << "] == " << v[i] << "\n";
		std::cout << "v.at(" << i << ") == " << v.at(i) << "\n";
	
	return 0;
} /* catch (std::out_of_range) {
	std::cerr << "Oops! Range error\n";
	return 1;
} catch (...) {		// catch other exceptions
	std::cerr << "Exception: something went wrong\n";
	return 2;
} */
