#include <iostream>

bool is_palindrome (const char*);
std::istream&  read_word (std::istream& is, char* buffer, int max);
int strLen (const char *);
void reverse (char*);
void strCpy (const char[], char[]);

int main (void) {
	const int max = 128;

	for (char s[max]; read_word (std::cin, s, max); ) 
		std::cout << s << " is" << (is_palindrome (s) ? "" : " not") << " a palindrome\n";

	return 0;
}

std::istream&  read_word (std::istream& is, char* buffer, int max) {
	is.width (max);

	is >> buffer;	// read whitespace-terminated words
					// add zero after last character read into buffer
	return is;
}

bool is_palindrome (const char* s) {
	char* newS = new char (strLen(s));

	strCpy	(s, newS);
	reverse	(newS);
	for (; *s != '\0' && *newS != '\0' && *s == *newS; ++s, ++newS);

	return *s == *newS;
}

int strLen (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++s, ++size);

	return size;
}

void reverse (char* s) {
	int len = strLen (s);
	char *end = s + len - 1, temp;

	for (; s < end; ++s, --end) {
		temp = *s;
		*s = *end;
		*end = temp;
	}
}

void strCpy (const char *src, char *des) {
	char *newDes = des;
	for (; *src != '\0'; ++src, ++newDes)
		*newDes = *src;
	*newDes = '\0';
}
