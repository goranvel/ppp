#include <iostream>

int main (void) {
	std::string firstName = "", friendName = "";
	char friendSex = 'm';
	int age = 0;

	std::cout << "Please enter recipians first name: ";
	std::cin >> firstName;

	std::cout << "How old is " << firstName << "? ";
	std::cin >> age;

	if (age <= 0 || age >= 110) {
		std::cerr << "error: you are kidding!\n";

		/*
		 * Keeps window alive
		 */ 
		std::cin.clear ();
		std::cout << "Please enter a character to exit\n";

		char ch;
		std::cin >> ch;
		/*
		 * end of winodw alive code
		 */
		
		return 0;
	}

	std::cout << "Please enter the name of another friend: ";
	std::cin >> friendName;

	std::cout	<<	"Is your firend male or female?\n"
					<<	"(Please enter m for male and f for female)\n";

	std::cin >> friendSex;

	std::cout << "\n\n\nDear " << firstName << ",\n";

	std::cout	<< "\tHow are you? I am fine. I miss you. \n"
					<< "I do not care about this letter or you :)\n"
					<< "All I care about is learning C++ :)\n"
					<< "Have you seen " << friendName << " lately?\n"
					<< "If you seen " << friendName << " pleas ask ";

	if (friendSex == 'f') 
		std::cout << "her";
	if (friendSex == 'm')
		std::cout << "him";
	
	std::cout	<< " to call me.\n";

	std::cout	<< "I heard you just head a birthday and you are " << age << " years old.";

	if (age == 17)
		std::cout	<< " Next year you will be able to vote. And have sex legally :)";
	if (age > 70)
		std::cout	<< " I hope you are enjoying retirement.";

	std::cout << "\n\nSincerely,\nGoran Veletic\n";

	return 0;
}
