#include <iostream>

struct God_struct {
	std::string name;
	std::string mythology;
	std::string vehicle;
	std::string weapon;

	God_struct (std::string n, std::string m, std::string v, std::string w) :
				name (n), mythology (m), vehicle(v), weapon(w) {
	}
};

class Link {
		Link *prev;
		Link *succ;
	public :
		God_struct god;

		Link (const God_struct& g, Link *p = nullptr, Link *s = nullptr) : 
				god (g), prev(p), succ(s) {
		}

		Link* insert (Link* n);
		Link* add (Link* n);
		Link* add_ordered(Link* n);
		Link* erase ();
		Link* find (const std::string& s);
		const Link* find (const std::string s) const;
		Link* advance (int n);

		Link* next () const {
			return succ;
		}

		Link* prevous () const {
			return prev;
		}
};

Link* Link::insert (Link *n) {
	if (n == nullptr)
		return this;
	
	if (this == nullptr)
		return n;

	n->succ = this;
	if (prev)
		prev->succ = n;
	
	n->prev = prev;
	prev = n;

	return n;
}

Link* Link::add (Link* n) {
	if (n == nullptr)
		return this;
	
	if (this == nullptr)
		return n;

	n->prev = this;
	if (succ)
		succ->prev = n;
	
	n->succ = succ;
	succ = n;

	return this;
}

Link* Link::add_ordered(Link* n) {
	if (n == nullptr)
		return this;
	if (this == nullptr)
		return n;

	if (n->god.name < this->god.name) {
		n->succ = this;
		this->prev = n;
		return n;
	}

	Link* temp = this;
	while (temp->god.name < n->god.name && temp->succ != nullptr) {
		temp = temp->succ;
	}

	if (temp->god.name < n->god.name && temp->succ == nullptr) {
		temp->succ = n;
		n->prev = temp;
	} else {
		n->prev = temp->prev;
		temp->prev->succ = n;
		n->succ = temp;
		temp->prev = n;
	}

	return this;
}

Link* Link::erase () {
	if (this == nullptr)
		return nullptr;

	Link* p = this;	
	if (p->succ)
		p->succ->prev = p->prev;
	
	if (p->prev)
		p->prev->succ = p->succ;

	return p->succ;
}

Link* Link::find (const std::string& s) {
	Link* p = this;
	while (p) {
		if (p->god.name == s)
			return p;

		p = p->succ;
	}

	return nullptr;
}

Link* Link::advance (int n) {
	if (this == nullptr)
		return nullptr;

	Link* p = this;
	if (n > 0)
		while (--n) {
			if (p->succ == nullptr)
				return nullptr;

			p = p->succ;
		}
	else if (n < 0) 
		while (++n) {
			if (p->prev == nullptr)
				return nullptr;

			p = p->prev;
		}
	
	return p;
}

void printAll (Link *p);

int main (void) {
	God_struct Thor		("Thor", "Norse", "chariot drawn by two giant goats", "Mjolnir");
	God_struct Stojan	("Stojan",	"Norse",	"",		"");
	God_struct Freia	("Freia",	"Norse",	"",		"");
	God_struct Goran	("Goran",	"Norse",	"",		"");
	God_struct Odin		("Odin",	"Norse",	"",		"");
	God_struct Zeus		("Zeus",	"Norse",	"",		"");
	God_struct Zoran	("Zoran",	"Norse",	"",		"");

	Link* norse_gods = new Link(Thor);
	norse_gods = norse_gods->add_ordered (new Link (Freia)); 
	norse_gods = norse_gods->add_ordered (new Link (Goran));
	norse_gods = norse_gods->add_ordered (new Link (Odin));
	norse_gods = norse_gods->add_ordered (new Link (Zoran));
	norse_gods = norse_gods->add_ordered (new Link (Stojan));
	norse_gods = norse_gods->add_ordered (new Link (Zeus));
	printAll(norse_gods);

	God_struct Hera		("Hera",		"Greek",	"",		"");
	God_struct Athena	("Athena",		"Greek",	"",		"");
	God_struct Mars		("Mars",		"Greek",	"",		"");
	God_struct Poseidon	("Poseidon",	"Greek",	"",		"");

	Link* greek_gods = new Link(Hera);
	greek_gods = greek_gods->insert (new Link(Athena));
	greek_gods = greek_gods->insert (new Link(Mars));
	greek_gods = greek_gods->insert (new Link(Poseidon));
	printAll(greek_gods);


	Link* p = greek_gods->find("Mars");
	if (p)
		p->god.name = "Area";
	printAll(greek_gods);

	Link* p2 = norse_gods->find("Zeus");
	if (p2)  {
		if (p2 == norse_gods)
			norse_gods = p2->next();
		p2->erase();
		greek_gods = greek_gods->insert(p2);
	}
	printAll(greek_gods);
	printAll(norse_gods);
	return 0;
}

void printAll ( Link *p) {
	std::cout << "{ ";
	while (p) {
		std::cout << p->god.name;
		if (p = p->next())
			std::cout << ", ";
	}
	std::cout << " }\n";
}
