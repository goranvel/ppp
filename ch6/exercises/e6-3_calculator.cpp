#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>

class Token {
	public:
		char kind;
		double value;

		Token (char ch) : kind (ch), 	value (0) {
		}

		Token (char ch, double val) : kind (ch), value (val) {
		}

		void print();
};

void Token::print () {
	std::cout << kind << " " << value << "\n";
}

class Token_stream {
	public:
		Token_stream () : full (false), buffer(0) {		// make a Token_stream that reads from cin
		}

		Token get();
		void putback (Token t);	// put a Token back
	private:
		bool full;
		Token buffer;	// here is where we keep a Token put back using putback();
};

void Token_stream::putback (Token t) {
	if (full)
		throw std::runtime_error("Bad token");	

	buffer = t;		// copy to to buffer
	full = true;	// buffer is now full
}

Token Token_stream::get() {
	if (full) {	// do we already have a Token ready?
		full = false;	// remove Token from buffer

		return buffer;
	}

	char ch;
	std::cin >> ch;

	switch (ch) {
		case '=':	// for "print"
		case 'x':	// for "quit"
		case '(':
		case ')':
		case '}':	// added in exercise 6-1
		case '{':	// added in exercise 6-1
		case '+':
		case '-':
		case '*':
		case '/': 
		case '!':
			return Token (ch);		// let each character represent itsefl
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': {
			std::cin.putback(ch);	// put digit back into the input stream
			double val;
			std::cin >> val;			// read a floating point number

			return Token  ('8', val);
		}
		default:
			throw std::runtime_error("Bad token");	
	}
}	

Token_stream ts;

double	expression();	// read and evaluate expression
double	term();
double	factorial();
double	primary();

int main (void) {
	try {
		double val = 0;

		std::cout << "Welcome to our simple calculator. ";
		std::cout << "Please enter expression using floating point numbers.\n";
		std::cout << "Available operations are +, -, * and /\n";
		std::cout << "To print type in '=' and to exit press 'x'\n";
		while (std::cin) {
			Token t = ts.get();
			if (t.kind == 'x')
				break;
			if (t.kind == '=')
				std::cout << "=" << val << "\n";
			else
				ts.putback(t);

			val = expression();
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
		return 1;
	} catch (...) {
		std::cerr << " unknown exception \n";
		return 2;
	}
	return 0;
}

double expression() {
	double left = term ();	// read and evaluate an Exrpession
	Token t = ts.get();		// get the next token
	while (true) {
		switch (t.kind) {		// see which kind of token is in
			case '+':
				left	+= term();	// read and evaluate a Term then do an add
				t		= ts.get();
				break;
			case '-':
				left	-= term();	// read and evaluate a Term then do a subtract
				t		= ts.get();	
				break;
			default :
				ts.putback(t);
				return left;	// return the value of Expression
		}
	}
}

double term () {
	double left = factorial();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/': {
				double divisor = primary();
				if (divisor == 0)
					throw std::runtime_error ("Cannot divide by zero");

				left /= divisor; 
				t = ts.get();
				break;
			}
			default :
				ts.putback(t);
				return left;
		}
	}  
}

double factorial() {
	double left = primary();
	Token t = ts.get();
	int factorial = 1;
	if (t.kind == '!') {
		for (int i = (int) left; i > 0; --i)
			factorial *= i;

		return factorial;
	} 

	ts.putback(t);
	return left;
}

double primary () {
	Token t = ts.get();
	switch (t.kind) {
		case '(': {	// handle '{' expression '}'
			double d = expression();
			t = ts.get();

			if (t.kind == '{')
				throw std::runtime_error ("'{' has to be closed");
			if (t.kind != ')')
				throw std::runtime_error  ("')' expected");
		
			return d;
		}
		case '{': {
			double d = expression();
			t = ts.get();

			if (t.kind != '}')
				throw std::runtime_error ("'}' expected");

			return d;
		}
		case '8':	// we use '8' to represent a number
			return t.value;	//	return to number's valu
		default	:
			throw std::runtime_error ("primary expected");
	} 
	return t.value;
}
