#include <iostream>

int e = 0, f = 0;

int main (void) {
	int a = 55;
	int b = 155;
	int *ap = &a;
	int *bp = &b;
	std::cout << "start\t" << ap << " ";
	std::cout << "end\t" << bp  << " ";
	std::cout << "Difference " << (ap - bp) << "\n";
	if (ap > bp)
		std::cout << "stack grows down\n";

	int *cp = new int;
	int *dp = new int;
	std::cout << "start\t" << &cp << " ";
	std::cout << "end\t" << &dp << " ";
	std::cout << "Difference " << (cp - dp) << "\n";
	if (cp < dp)
		std::cout << "heap grows up\n";

	int *ep = &e;
	int *fp = &f;
	std::cout << "start\t" << ap << " ";
	std::cout << "end\t" << &bp  << " ";
	std::cout << "Difference " << (&a - &b) << "\n";
	if (ep < fp)
		std::cout << "static storage grows down\n";

	std::cout << (ap > ep) << "\n";
	return 0;
}
