#include <iostream>

char *cat_dot (const char*, const char*);
char *cat_delim (const char*, const char*, const char*);
int strLen (const char*);

int main (void) {
	char* dot = cat_dot ("Hello", "world");
	char* delim = cat_delim ("Hello", "world", "<>") ;
	std::cout << dot << "\n";
	std::cout << delim << "\n";

	delete[] dot;
	return 0;
}

char *cat_delim (const char* s1, const char* s2, const char* delim) {
	char *cat = new char[strLen(s1) + strLen(s2) + strLen(delim)];
	char *retrun = cat;
	for (; *s1 != '\0'; ++s1, ++cat)
		*cat = *s1;

	for (; *delim != '\0'; ++delim, ++cat)
		*cat = *delim;

	for (int i = 0; *s2 != '\0'; ++i, ++s2, ++cat)
		*cat = *s2;
	
	*cat = '\0';
	return retrun;
}

char *cat_dot (const char* s1, const char* s2) {
	char *cat = new char[strLen(s1) + strLen(s2)];
	char *retrun = cat;
	for (; *s1 != '\0'; ++s1, ++cat)
		*cat = *s1;

	*cat++ = '.';

	for (; *s2 != '\0'; ++s2, ++cat)
		*cat = *s2;
	
	*cat = '\0';
	return retrun;
}

int strLen (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++s, ++size);

	return size;
}
