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
		case ';':	// for "print"
		case 'q':	// for "quit"
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/': 
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
double	primary ();
// Token		get_token ();	// read a token from cin
void		keep_window_open(std::string s);

int main (void) {
	try {
		double val = 0;
		while (std::cin) {
//			std::cout << "+" << expression() << '\n';
			Token t = ts.get();
			if (t.kind == 'q')
				break;
			if (t.kind == ';')
				std::cout << "=" << val << "\n";
			else
				ts.putback(t);

			val = expression();
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
		return 1;
	} catch (...) {
		std::cerr << "exception \n";
		return 2;
	}
	return 0;
}

double expression() {
	double left = term ();	// read and evaluate an Exrpession
	Token t = ts.get();		// get_token();	// get the next token
	while (true) {
		switch (t.kind) {	// see which kind of token is in
			case '+':
				left	+= term();	// read and evaluate a Term then do an add
				t		= ts.get();		// get_token();
				break;
			case '-':
				left	-= term();	// read and evaluate a Term then do a subtract
				t		= ts.get();		// get_token();	
				break;
			default :
				ts.putback(t);
				return left;		// return the value of Expression
		}
	}
}

double term () {
	double left = primary();
	Token t = ts.get();	// get_token();

	while (true) {
		switch (t.kind) {
			case '*':
				left *= primary();
				t = ts.get(); // get_token();
				break;
			case '/': {
				double divisor = primary();
				if (divisor == 0)
					throw std::runtime_error ("Cannot divide by zero");

				left /= divisor; 
				t = ts.get();	// get_token();
				break;
			}
			default :
				ts.putback(t);
				return left;
		}
	}  
}

double primary () {
	Token t = ts.get(); // get_token();
	switch (t.kind) {
		case '(' :	{// handle '(' expression ')'
			double d = expression();
			t = ts.get();	// get_token();

			if (t.kind != ')')
				throw std::runtime_error  ("')' expected");

			return d;
		}
		case '8' :	// we use '8' to represent a number
			return t.value;	//	return to number's valu
		default	:
			throw std::runtime_error ("primary expected");
	} 
	return t.value;
}
/*
Token get_token() {
	char ch;
	std::cin >> ch;

	switch (ch) {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
			return Token(ch);
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
			std::cin >> val;
			return Token('8', val);
		}
		default :
			throw std::runtime_error("Bad token");	
	}
} */
