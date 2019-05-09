#include <iostream>
#include <iomanip>

int main (void) {
	std::cout << std::setw (4) << "| "	<< "Last name"		<< std::setw (11) 	<< "| "
													<< "First name"	<< std::setw (10)	<< "| "
													<< "Phone number"	<< std::setw (8) << "| "
													<< "Email\n";

	std::cout << "--+" <<	"-------------------+" <<
									"-------------------+" <<
									"-------------------+" <<
									"------------------------\n";

	std::cout << std::setw (4) << "1 | "	<< "Mark"							<< std::setw (16) << "| "
														<< "Twinky"							<< std::setw (14) << "| "
														<< "(012) 123-2345"				<< std::setw (6)	<< "| "
														<< "mark.twinky@smail.com\n";

	std::cout << std::setw (4) << "2 | "	<< "Brandon"						<< std::setw (13) << "| "
														<< "Pinky"							<< std::setw (15) << "| "
														<< "(012) 123-2345"				<< std::setw (6)	<< "| "
														<< "brandon.pinky@smail.com\n";

	std::cout << std::setw (4) << "3 | "	<< "Jacob"							<< std::setw (15) << "| "
														<< "Dinky"							<< std::setw (15) << "| "
														<< "(012) 123-2345"				<< std::setw (6)	<< "| "
														<< "jacobd@email.com\n";

	std::cout << std::setw (4) << "4 | "	<< "Brad"							<< std::setw (16) << "| "
														<< "Silk"							<< std::setw (16) << "| "
														<< "(012) 123-2345"				<< std::setw (6)	<< "| "
														<< "bradsilk@smail.com\n";

	std::cout << std::setw (4) << "4 | "	<< "Alexandra"						<< std::setw (11) << "| "
														<< "Silly"							<< std::setw (15) << "| "
														<< "(012) 123-2345"				<< std::setw (6)	<< "| "
														<< "asilly@smail.com\n";


	return 0;
}
