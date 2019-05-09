#include <iostream>
#include <cctype>
#include <fstream>

int main (void) {
	std::string filename = "test.txt";
/*	std::cout << "Please enter input file name: "
	std::cin >> filename; */
	std::ifstream ifs (filename.c_str());
	
	std::string input;

	int	spaces,	alphas,	digits,	hexes,	uppers, 
			lowers,	alnums,	ctrls,	puncts,	prints, graphs;
	spaces = alphas = digits = hexes = uppers = lowers = alnums = ctrls = puncts = prints = graphs = 0;

	char c;
	while (ifs.get(c)) {
		if (std::isspace(c))
			++spaces;
		if (std::isalpha(c))
			++alphas;
		if (std::isdigit(c))
			++digits;
		if (std::isxdigit(c))
			++hexes;
		if (std::isupper(c))
			++uppers;
		if (std::islower(c))
			++lowers;
		if (std::isalnum(c))
			++alnums;
		if (std::iscntrl(c))
			++ctrls;
		if (std::ispunct(c))
			++puncts;
		if (std::isprint(c))
			++prints;
		if (std::isgraph(c))
			++graphs;
	}
	
	std::cout <<	"Spaces:\t\t\t"	<< spaces	<< "\n" <<
						"Letters:\t\t"		<< alphas	<< "\n" <<
						"Digits:\t\t\t"	<< digits	<< "\n" <<
						"Hex:\t\t\t"		<< hexes		<< "\n" <<
						"Uppercase:\t\t"		<< uppers	<< "\n" <<
						"Lowercase:\t\t"	<< lowers	<< "\n" <<

						"Letters or Number:\t"		<< alnums	<< "\n" <<
						"Control characters:\t"		<< ctrls		<< "\n" <<
						"Punctuations:\t\t"			<< puncts	<< "\n" <<
						"Printable characters\t"	<< prints	<< "\n" <<
						"Graphical characters\t"	<< graphs	<< "\n";

	return 0;
}
