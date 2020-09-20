#include <iostream>

class Link {
		Link *prev;
		Link *succ;
	public :
		std::string value;

		Link (const std::string& v, Link *p = nullptr, Link *s = nullptr) : 
				value (v), prev(p), succ(s) {
		}

		Link* insert (Link *n);
		Link* add (Link* n);
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
	if (prev)
		prev->succ = n;
	
	n->succ = succ;
	succ = n;

	return n;

}

Link* Link::erase () {
	if (this == nullptr)
		return nullptr;

	Link* p = this, *next = succ;
	if (p->succ)
		p->succ->prev = p->prev;
	
	if (p->prev)
		p->prev->succ = p->succ;
	
	delete p;
	return next;
}

Link* Link::find (const std::string& s) {
	Link* p = this;
	while (p) {
		if (p->value == s)
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
	// Link * norse_gods = new Link();
	Link* norse_gods = new Link("Thor");
	norse_gods = norse_gods->insert (new Link ("Odin"));
	norse_gods = norse_gods->insert (new Link ("Zeus"));
	norse_gods = norse_gods->insert (new Link ("Freia"));
	printAll(norse_gods);

	Link* greek_gods = new Link("Hera");
	Link* Athena = new Link("Athena");
	greek_gods = greek_gods->insert (Athena);
	greek_gods = greek_gods->insert (new Link("Mars"));
	greek_gods = greek_gods->insert (new Link("Poseidon"));
	printAll(greek_gods);
	greek_gods->erase();
	printAll(greek_gods);
	Link* p = greek_gods->find("Mars");
	if (p)
		p->value = "Area";
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
		std::cout << p->value;
		if (p = p->next())
			std::cout << ", ";
	}
	std::cout << " }\n";
}
