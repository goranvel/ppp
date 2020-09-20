#include <iostream>

int strLen (const char *);
bool is_palindrome (const char*);
void reverse (char[]);
void strCpy (const char[], char[]);
std::istream& read_word(std::istream&, char*, int);

int main (void) {
	char rev[] = "abcdfdcba";
	
	std::cout << "Workd " << rev << " is" << (is_palindrome (rev) ? "" : " not") << " a palindrome.";

	return 0;
}

bool is_palindrome (const char* s) {
	char newS[strLen(s)];
	strCpy (s, newS);
	reverse (newS);

	int i = 0;	
	for (; s[i] != '\0' && newS[i] != '\0' && s[i] == newS[i]; ++i);

	return s[i] == newS[i];
}

int strLen (const char* s) {
	int size = 0;
	for (; *s != '\0'; ++s, ++size);

	return size;
}

std::istream& read_word (std::istream& is, char* buffer, int max) {
	is.width (max);
	is >> buffer;

	return is;
}

void reverse (char s[]) {
	char temp;
	int len = strLen (s);
	for (int i = 0; i < (len >> 1); ++i) {
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
	s[len] = '\0';
}

void strCpy (const char src[], char des[]) {
	int i = 0;
	for (; src[i] != '\0'; ++i)
		des[i] = src[i];
	
	des[i] = '\0';
}
