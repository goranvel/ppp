#include <iostream>

int strcmp (const char*, const char*);
int strLen (const char*);
int main (void) {
	std::cout << strcmp ("Hella", "Hello");
	return 0
}

int strcmp (const char* s1, const char* s2) {
	for (; *s1 != '\0' && *s2 != '\0' && *s1 == *s2; ++s1, ++s2);
	return *s1 - *s2;
}

int strLen (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++s, ++size);

	return size;
}
