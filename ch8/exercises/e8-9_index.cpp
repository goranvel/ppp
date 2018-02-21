#include <iostream>
#include <stdexcept>
#include <vector>

double index (const std::vector <double>& price, const std::vector <double>& wieght);

int main (void) {
	try { 
		double weight = 0, price = 0;
		std::vector<double> weights, prices;
		std::cout << "Please enter price followwed by weight\n";
		while (std::cin >> price >> weight) {
			weights.push_back(weight);
			prices.push_back(price);
		}
		
		std::cout << "INDEX: " << index (weights, prices) << "\n";

	} catch (std::runtime_error& e) {
		std::cout << "RUNTIME ERROR: " << e.what() << "\n";
	}

	return 0;
}

double index (const std::vector <double>& price, const std::vector <double>& weight) {
	if (price.size() != weight.size())
		throw std::runtime_error ("Price and weight have to be the same size");
	double index = 0;

	for (int i = 0; i < price.size(); ++i)
		index += price[i] * weight[i];

	return index;
}
