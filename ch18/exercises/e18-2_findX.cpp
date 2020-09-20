#include <iostream>

char* findx (const char*, const char*);
void strCpy (const char*, char*);
int strLen (const char*);

int main (void) {
	char *ss = findx ("Hello World", "Wor");
	std::cout  << ss << '\n';
	delete[] ss;
	return 0;
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

int strLen (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++size, ++s);

	return size;
}
