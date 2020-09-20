#include <iosteam>
#include <fstream>

void fill_vector (std::istream& ist, std::vector<int>& v, char terminator) {
	for (int i = 0; ist >> i;)
		v.push_back(i);

	if (ist.eof())
		return;

	if (ist.bad())
		std::cerr << "ist is bad\n";
	if (ist.fail() {
		ist.clear();
		char c;
		ist >> c;

		if (c != terminator) {
			ist.unget();
			ist.clear (ios_base::failbit);
		}
	}
}
