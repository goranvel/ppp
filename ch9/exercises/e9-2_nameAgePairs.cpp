#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Name_pairs {
		std::vector<std::string> name;
		std::vector<double> age;
		void moveAges (std::vector<std::string> old_names);
		int find (const std::vector<std::string> old_name, const std::string& n, int start);
	public:
		Name_pairs () : name (0), age (0) {
		}

		void read_name () {
			std::string n;
			while (true) {
				std::cin >> n;
				if (!std::cin)
					throw std::runtime_error ("Bad input.\n");
				if (n == "#")
					return;

				name.push_back (n);
			}
		}

		void read_age () {
			double a = 0;
			for (int i = 0; age.size() < name.size(); ++i) {
				std::cout << "Enter age for " << name[i] << "\n";
				std::cin >> a;
				age.push_back (a);
			}
		}

		void sort () {
			std::vector<std::string> old_name = name;
			std::sort(name.begin(), name.end());
			moveAges (old_name);
		}

		void print ();
};

void Name_pairs::print () {
   for (int i = 0; i < name.size (); ++i) {
      std::cout << "Name: " << name[i] << " age: " << age[i] << "\n";
   }
}

void Name_pairs::moveAges (const std::vector<std::string> old_name) {
	std::vector <double> new_age = age;
   std::vector <bool> checked (name.size(), false);
   int n = 0;

   try {
      for (int i = 0; i < name.size(); ++i) {
         n = find (old_name, name[i], 0);
         if (!checked[n]) {
            new_age[i] = age[n];
            checked[n] = true;
         } else {
            n = find (old_name, name[i], n + 1);
            new_age[i] = age[n];
            checked[n] = true;
         }
      }
		age = new_age;
   } catch (std::runtime_error& e) {
      std::cerr << "ERROR: " << e.what() << "\n";
   }
}

int Name_pairs::find (const std::vector<std::string> old_name, const std::string& n, int start) {
   if (start > old_name.size())
      throw std::runtime_error ("ERROR: starting value cannot be greater than size of vector.\n");

   for (; start < old_name.size(); ++start) 
      if (old_name[start] == n)
         return start;

   return -1;
}



int main (void) {
	try {
		Name_pairs np;
		std::cout << "Please enter names:\n";
		np.read_name();
		np.read_age();
		np.print();
		np.sort();
		np.print();
	} catch (std::runtime_error& e) {
		std::cerr << "Error: " << e.what();
	}

	return 0;
}
