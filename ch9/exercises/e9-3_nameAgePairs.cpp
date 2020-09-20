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
			std::cout << "Please enter names:\n";
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

			if (name.size () > age.size())
				throw std::runtime_error ("Vector `age` does not contain same number of element as `name`.");

		}

		void sort () {
			std::vector<std::string> old_name = name;
			std::sort(name.begin(), name.end());
			moveAges (old_name);
		}


		std::vector<std::string> getName () const {
			return name;
		}
		
		std::vector<double> getAge () const {
			return age;
		}

		int size() const {
			return name.size();
		}
//		void print ();
};

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

// void Name_pairs::print () {
std::ostream& operator<< (std::ostream& os, const Name_pairs& n) {
	for (int i = 0; i < n.getName().size(); ++i) 
		os << "Name: " << n.getName()[i] << "\tage: " << n.getAge()[i] << "\n";

	return os;
}

bool operator== (Name_pairs a, Name_pairs b) {
	if (a.size() != b.size())
		return false;

	a.sort();
	b.sort();

	for (int i = 0; i < a.getName().size(); ++i)
		if (a.getName()[i] != b.getName()[i] || a.getAge()[i] != b.getAge()[i])
			return false;
	
	return true;
}

bool operator!= (Name_pairs a, Name_pairs b) {
	return !(a == b);
}

int main (void) {
	try {
		Name_pairs a, b;
	
		a.read_name();
		a.read_age();
		b.read_name();
		b.read_age();

		std::cout << (a == b) << "\n";
	} catch (std::runtime_error& e) {
		std::cerr << "Error: " << e.what();
	}

	return 0;
}
