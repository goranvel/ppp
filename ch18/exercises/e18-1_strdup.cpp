#include <iostream>
#include <cstring>

int strLen (const char*);
char* strDup (const char*);

int main (void) {
	char hw[] = "Hello World";
	char *chw = strDup(hw);
	std::cout << chw << "\n";
	delete[] chw;

	return 0;
}

char* strDup (const char* s) {
	char *newS = new char[strLen(s) + 1];
	char *start = newS;
	for (; *s != '\0'; ++s, ++newS) 
		*newS = *s;

	*newS = '\0';
	std::cout << newS << "<<\n";
	return start;
}

int strLen (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++size, ++s);

	return size;
}
