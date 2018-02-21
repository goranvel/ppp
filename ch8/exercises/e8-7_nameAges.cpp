#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

void printv (const std::vector<std::string>& name, const std::vector<int>& v);
void moveAges (const std::vector<std::string>& names, 
						const std::vector<std::string>& new_names, 
							const std::vector<int>& ages,
								std::vector<int>& new_ages);
int find (const std::vector<std::string>& names, const std::string& name, int start);

int main (void) {
	std::string name;
	int age;
	std::vector <std::string> names;
	std::vector <int> ages;
	std::cout << "Please enter 5 names followed by the age:\n";

	while (names.size() < 5 && std::cin >> name >> age) {
		names.push_back (name);
		ages.push_back (age);
	}
	
	std::vector<std::string> new_names = names;
	std::vector<int> new_ages (names.size(), -1);
	printv (names, ages);

	sort(new_names.begin(), new_names.end());
	moveAges (names, new_names, ages, new_ages);

	printv (new_names, new_ages);
}

void printv (const std::vector<std::string>& names, const std::vector<int>& ages) {
	for (int i = 0; i < names.size (); ++i) {
		std::cout << "Name: " << names[i] << " age: " << ages[i] << "\n";
	}
}

void moveAges (const std::vector<std::string>& names, 
						const std::vector<std::string>& new_names, 
							const std::vector<int>& ages,
								std::vector<int>& new_ages) {
	std::vector <bool> checked (names.size(), false);
	int n = 0;
	for (int i = 0; i < names.size(); ++i) {
		n = find (names, new_names[i], 0);
		if (!checked[n]) {
			new_ages[i] = ages[n];
			checked[n] = true;
		} else {
			n = find (names, new_names[i], n + 1);
			new_ages[i] = ages[n];
			checked[n] = true;
		}
	}
}

int find (const std::vector<std::string>& names, const std::string& name, int start) {
	if (start > names.size()) 
		throw std::runtime_error ("ERROR: starting value cannot be greater than size of vector.\n");

	for (; start < names.size(); ++start)
		if (names[start] == name)
			return start;

	return -1;
}
