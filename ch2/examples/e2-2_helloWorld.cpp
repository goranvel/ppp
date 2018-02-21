// What is programming
// Why learn C++

/* HelloWorld.cpp
 *		outputs Hello World to the shell or command line
 *	
 * Written by: somebody
 */

// #include "std_lib_facilities.h"]
#include <iostream>
/* includes can have following structure
		#include <iostream>
		#include "Hello.h"
*/

// inlcude directives tells compiler to include library of funcions

// EVERY PROGRAM IN C++ STARTS IN MAIN FUNCITON
//		function is a group of code packaged together to be reused
int main (void) 
/*^	^		^	
  |	|		+--	function arguments
  |	+--------	name of the function 
  +------------	return type of function
*/
{	// Start of function 

	std::cout << "Hello, World!\n";

	// std::cout is standard output stream
	//	<< means put into or push into output stream

	// \n is new line character and means go to the next line
	// NOTE:	In Unix/Linux (including Mac OS) \n returns to begining of line
	//			while on Windows it goes to the next line but same column as it was before \n

	// THESE ARE SINGLE LINE COMMENTS

	/*
		thesee
		are
		multi
		line
		comments
	*/

	// Comments are written to descirbe the program (most of the time)

	// NOTE:
	//		FOR WINDOWS USE: wait () or
	//		std::cin.clear;
	//		std::cout << "Enter any character to exit
	//		char c;
	//		std::cin >> c

	return 0; // returnin value
} // END OF FUNCTION
