#include <iostream>

char *find (char* s, const char* x);

int main (void) {
	char x[] = "Well";
	char y[] = "Hello World!!! Well done!!!";
	char *s = find (y, x);
	std::cout << s << "\n"; 

	delete[] s;

	return 0;
}

char *find (char* s, const char* x) {
	int size = 0;
	char *found = nullptr;
	for (; *s != 0; ++s)
		if (*x == *s) {
			found = s;
			for (size = 0; *s != 0 && *x != 0 && *(s + size) == *(x + size); ++size);
		}

	found = new char(size);
	for (int i = 0; i < size; ++i)
		*(found+i) = *(x++);
	
	found[size] = 0;
	return found;
}
