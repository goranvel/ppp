#include <iostream>
#include <cstring>

int strLen (const char*);
char* strDup (const char*);
char* findx (const char*, const char*);
void strCpy (const char*, char*);
int strcmp (const char*, const char*);

int main (void) {
	char* bad = new char[1000];
	char* newBad = new char[1000];
	for (int i = 0; i < 1000; ++i) {
		*(bad + i) = 'A';
	}

	std::cout << bad << "\n\n\n";
	strCpy (bad, newBad);
	std::cout << "" << newBad << "\n";
/*
	char *chw = strDup(hw);
	std::cout << chw << "\n";
	delete[] chw; */

	return 0;
}

char* strDup (const char* s) {
	std::cout << ">> " << s << " <<\n";
	char *newS = new char[strLen(s) + 1];
	char *start = newS;
	for (; *s != '\0'; ++s, ++newS) 
		*newS = *s;

	*newS = '\0';
	return start;
}

char* findx (const char* s, const char* x) {
	int xSize = strLen (x);
	for (; *s != '\0'; ++s) {
		if (*s == *x) {
			char* ss = new char[strLen (s)]; 
			for (; *s == *x; ++s, ++x)
				if (*(x + 1) == '\0' && *s == *x) {
					strCpy ((s - xSize + 1), ss);
					return ss;
				}
		}
	}

	return nullptr;
}

void strCpy (const char* src, char* des) {
	char *newDes = des;
	for (; *src != '\0'; ++src, ++newDes)
		*newDes = *src;

	*newDes = '\0';
}

int strcmp (const char* s1, const char* s2) {
	for (; *s1 != '\0' && *s2 != '\0' && *s1 == *s2; ++s1, ++s2);
	return *s1 - *s2;
}

int strLen (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++s, ++size);

	return *s == '\0' ? size : 0;
}
