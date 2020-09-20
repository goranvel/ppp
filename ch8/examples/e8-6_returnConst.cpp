#include <iostream>
#include <vector>
class MyClass {
	public :
		std::string a;
		MyClass (std::string n);
		std::string getIt ();
};

MyClass::MyClass (std::string n) {
	a = n;
}

std::string MyClass::getIt() {
	return a;
}	
const int abc ();
const MyClass cba ();
MyClass cba2 ();
const std::vector<int> bcd () ;

int main (void) {
	int a = abc() + 3;
	std::string b = cba().getIt();
	std::string c = cba2().getIt();
	
		
	
//	std::cout << a << " " << b << "\n";
//	std::vector<int> v = bcd().push_back(5); // illegal
	return 0;
}

const int abc () {
	const int aa = 5;

	return aa;
}

const MyClass cba () {
	const MyClass m ("HELL");

	return m;
}
MyClass cba2 () {
	const MyClass m ("HELL");

	return m;
}

const std::vector<int> bcd () {
	const std::vector<int> v (4,0);

	return v;
}
