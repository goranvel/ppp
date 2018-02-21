class Patron {
		std::string name;
		int library_card;
		double fees;
	public :
		Patron (std::string n, int lc, double f) : name(n), library_card(lc), fees(f) {
		}

		// getters
		std::string getName () {
			return name;
		}

		int getLibraryCard () {
			return library_card;
		}

		double getFees () {
			return fees;
		}

		bool owes () {
			return fees > 0;
		}

		// setters
		void setFees (double f) {
			fees = f;
		}
};

int main (void) {
	return 0;
}
