#include <iostream>

char* strCopy (const char*);

int main (void) {
	char s[] = "hello world!!!";
	char* b = strCopy (s);

	std::cout << b << "\n";

	delete[] b;
	return 0;
}

char* strCopy (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++size, ++s);
	s-=size;

	char *ret = new char(size);
	char *temp = ret;
	for (; *s != '\0'; ++s, ++temp)
		*temp = *s;

	return ret;
}
