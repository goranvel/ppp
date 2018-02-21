#include <iostream>
#include <vector>

std::vector<std::string> nouns;
std::vector<std::string> verbs;
std::vector<std::string> conj; // hold conjuctions

bool is_sentence ();
bool is_noun (std::string w);
bool is_verb (std::string w);
bool is_conjuction (std::string w);

int main () {
	nouns.push_back("Birds");
	nouns.push_back("Fish");
	nouns.push_back("C++");

	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.push_back("swim");

	conj.push_back("and");
	conj.push_back("or");
	conj.push_back("but");
	std::string sentence = "";
	bool checked;	// this is due to bug that it will say multiple time Not OK
						// for each word once
	while (std::cin) {
		checked = false;
		if (is_sentence())
			std::cout << "OK";
		else if (!is_sentence() && !checked) {
			checked = true;
			std::cout << "Not OK";
		}

		std::cout << "\nTry again.\n";
	}

		
	return 0;
}

bool is_sentence () {
	std::string word;
	std::cin >> word;
	if (is_noun(word)) {
		std::cin >> word;

		if (is_verb(word)) {
			std::string word3;
			std::cin >> word3;
			if (word == ".")
				return true;
			else if (is_conjuction (word3)) 
				return is_sentence();
		}
	}

	return false;
}

bool is_noun (std::string word) {
	for (int i = 0; i < nouns.size(); ++i)
		if (word == nouns[i])
			return true;

	return false;
}

bool is_verb (std::string word) {
	for (int i = 0; i < verbs.size(); ++i)
		if (word == verbs[i]) 
			return true;

	return false;
}

bool is_conjuction (std::string word) {
	for (int i = 0; i < conj.size(); ++i)
		if (word == conj[i])
			return true;

	return false;
}

