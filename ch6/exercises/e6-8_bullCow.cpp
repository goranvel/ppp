#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

int main (void) {
	std::vector<char> randomIn(4, 0);
	std::vector<char> userIn (4, 0);
	int bullCnt = 0, cowCnt = 0;

	srand(time(NULL));

	randomIn[0] = rand() % 26 + 'a';
	while (( randomIn[1] = rand() % 10 + 'a') == randomIn[0] );
	while (( randomIn[2] = rand() % 10 + 'a') == randomIn[0] ||
               randomIn[2] == randomIn[1] );
	while (( randomIn[3] = rand() % 10 + 'a') == randomIn[0] ||
					randomIn[3] == randomIn[1] ||
                  randomIn[3] == randomIn[2] );

   std::cout << "Please enter 4 digit number.\n";

	while ( userIn[0] != -1) {
		std::cin >> userIn[0] >> userIn[1] >> userIn[2] >> userIn[3];
		for (int i = 0; i < randomIn.size(); ++i)
			std::cout << randomIn.at(i);

		std::cout << "\n";
	
		for (int i = 0; i < userIn.size(); ++i)
         if (userIn[i] == randomIn[i])
            ++bullCnt;
         else
            for (int j = 0; j < randomIn.size(); ++j)
               if (userIn[i] == randomIn[j])
                  ++cowCnt;

		if (bullCnt > 0) {
         std::cout << bullCnt << " bull";
         if (bullCnt > 1)
            std::cout << "s";

         if (cowCnt > 0)
            std::cout << " and ";
         else
            std::cout << ".\n";
		}

      if (cowCnt > 0) {
         std::cout << cowCnt << " cow";
         if (cowCnt > 1)
            std::cout << "s";
         std::cout << ".\n";
      }

      if (bullCnt == 4) {
         std::cout << "Congrats you got it!!!!\n";
         for (int i = 0; i < randomIn.size(); ++i)
            std::cout << randomIn.at(i);

			std::cout << "\n";
			return 0;
		}

		bullCnt = 0;
		cowCnt = 0;
		std::cout << "Try again!\n";
	}


   return 0;
}

