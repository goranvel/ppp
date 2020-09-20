#include <iostream>

void toUpper (char *s);
void toLower (char *s);

int main (void) {
	char s[] = "Hello World!!!";

	toLower(s);

	std::cout << s << "\n";

	return 0;
}

void toUpper (char *s) {
	for (; *s != 0; ++s) 
		if (*s >= 'a' && *s <= 'z')
			*s -= 'a' - 'A';
}

void toLower (char *s) {
	for (; *s != 0; ++s)
		if (*s >= 'A' && *s <= 'Z')
			*s -= 'A' - 'a';
}
