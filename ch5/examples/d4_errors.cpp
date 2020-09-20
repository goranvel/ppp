#include <iostream>
#include <exception>
#include <vector>

int main (void) {
	try {
//		std::Cout << "Success!\n"; // #1
//			  ^ capital c

//		std::cout << "Success!\n;  // #2
//										^ missing quotes (")

//		std::cout << "Success" << !\n" // #3
//										  ^ missing quotes (") as well									

//		std::cout << success << "\n"; // #4
//						 ^^^^^^^ either missing quotes or underfined variable success

/*		START OF #5
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// * /
		std::string res = 7;
//		^^^^^^^^^^^ should be int
		std::vector<int> v(10);
		v[5] = res;
		std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #5
*/

/*
		START OF #6
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::vector<int> v(10);
		v[5] = 7;
//				 ^ either change the value
//					v change this to ==
		if (v[5] != 7)
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #6
*/

/*
		START OF #7
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		bool cond = true;
//			 vvvv declare cond as
		if (cond)
			std::cout << "Success!\n";
		else
			std::cout << "Fail!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #7
*/

/*
		START OF #8
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		bool c = false;
//					^^^^^ change this to 'true'
		if (c)
			std::cout << "Success!\n";
		else
			std::cout << "Fail!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #8
*/

/*
		START OF #9
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::string s= "ape";
//				         v should be changed to > 
		boo c = "fool" < s;
//	   ^^^ this should be bool	
		if (c)
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #9
*/

/*
		START OF #10
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::string s = "ape";
//				vv change to '!='
		if (s == "fool")
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #10
*/

/*
		START OF #11
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::string s = "ape";
//				vv change to '!='
		if (s == "fool")
			std::cout < "Success!\n";
//						 ^ double < needed (<<)

/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #11
*/

/*
		START OF #12
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::string s = "ape";
//				v change to '!='
		if (s + "fool")
			std::cout < "Success!\n";
//						 ^ double < needed (<<)


/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #12
*/

/*
		START OF #13
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::vector<char> v(5);
//							 v change to 'i'
		for (int i = 0; 0 < v.size(); ++i);
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #13
*/

/*
		START OF #14
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::vector<char> v(5);
//								 v delete '=' it should be '<'
		for (int i = 0; i <= v.size(); ++i);
			std::cout << "Success!\n";

/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #14
*/

/*
		START OF #15
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::string s = "Success!\n";
//								  v change this to '9' or to 's.size()'
		for (int i = 0; i < 9; ++i)
			std::cout << s[i];
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #15
*/

/*
		START OF #16
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
//					 vvvv remove 'then' it is not used in C++
		if (true) then
			std::cout << "Success!\n";
		else
			std::cout << "Fail!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #16
*/

/*
		START OF #17
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		int x = 2000;
		char c = x;
//				   ^ char can only hold values -128 to 127 this comes to -48
//					vvvvvv solutions is either cast '2000' to char
		if (c == (char) 2000)
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #17
*/

/*
		START OF #18
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::string s = "Success!\n";
//								  v change this to '9' or to 's.size()'
		for (int i = 0; i < 10; ++i)
			std::cout << s[i];
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #18
*/

/*
		START OF #19
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
//					  v add type to vector 'std::vecter<TYPE>'
		std::vector v(5);
		for (int i = 0; i <= v.size(); ++i);
			std::cout << "Success!\n";

/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #19
*/

/*
		START OF #20
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		int i = 0;
		int j = 9;
		while (i < 10)
			++j;
//			  ^ change this to i

		if (j < i)
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #20
*/

/*
		START OF #21
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		int x = 2;
//				  ^ change to something elese than 2
		double d = 5/(x - 2);
//				v change this to <= to since 5/(unknowns) is like to be less than
		if (d == 2*x + 0.5)
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #21
*/

/*
		START OF #22
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
//						vvvvv remove <char>
		std::string<char> s = "Success!\n";
		for (int i = 0; i <= 10; ++i) 
			std::cout << s[i];
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #22
*/

/*
		START OF #23
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		int i = 0;
//		declare j
		while (i < 10)
			++j;
//			  ^ should be 'i'

		if (j < i)
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #23
*/

/*
		START OF #24
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		int x = 4;
		double d = 5/(x-2);
	
//				v this houls be '<=' or '==' not '='
		if (d = 2 * x + 0.5)
			std::cout << "Success!\n";
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #24
*/

/*
		START OF #25
		vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
* /
		std::cin << "Success";
//			  ^^^ should be std::cout
/ *
		^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		END OF #25
*/
		std::cout << "DONE!!!\n";
	} catch (std::exception &e) {
		std::cerr << "error: " << e.what()  << "\n";

		return 1;
	} catch (...) {
		std::cerr << "Oops unknown exception!\n";

		return 2;
	}

	return 0;
}
