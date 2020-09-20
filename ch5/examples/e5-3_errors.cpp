#include <iostream>

int area (int lenght, int width);
int area (int lw);

int main (void) {
//	int s1 = area(7;	// error: expected ‘)’ before ‘;’ token
//	int s2 = area(7)	// error: too few arguments to function ‘int area(int, int)’ 
							//		if area(int):
							// error: expected , or ; before return
//	Int s3 = area(7); // error: ‘Int’ was not declared in this scope
							//			AND
							// error: expected ‘;’ before ‘s3’
//	int s4 = area('7);// error: missing terminating ' character

//	int x0 = arena(7);// error: ‘arena’ was not declared in this scope
//	inr x1 = area(7);	// error: too few arguments to function ‘int area(int, int)’ 
//	int x2 = area ("seven", 2); // invalid conversion from ‘const char*’ to ‘int’

	int x4 = area (10, -7);
	std::cout << x4 << " ";
	int x5 = area (10.7, 9.3);
	std::cout << x5 << " ";
	char x6 = area (100,	9999);
	std::cout << (int) x6 << " ";

	return 0;
}

int area (int lenght, int width) {
	return lenght * width;
}

int area (int lw) {
	return area (lw, lw);
} 
