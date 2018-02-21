namespace Chrono {
	enum class Month {
		jan = 1,	
		feb,	mar,	apr,	may,	jun,
		jul,	avg,	sep,	oct,	nov,	
		dec
	};

	class Date {
			int y, d;
			Month m;
		public :
			class Invalid {}; // exception class

			Date (int y, Month m, int d);		// check for valid date and time
			Date ();	// default constructor
			
			//  non modiffying operator 
			int day () const {
				return d;
			}
			Month month () const { 
				return m; 
			}
			int year () const { 
				return y; 
			} 
			
			// modifying operation
			void add_day (int n);
			void add_month(int n);
			void add_year(int n);
	};

	bool is_date (int y, Month m, int d);
	bool leapyear(int y);

	bool operator == (const Date& a, const Date& b);
	bool operator != (const Date& a, const Date& b);

	std::ostream& operator << (std::ostream& os, const Date d);
	std::istream& operator >> (std::ostream& is, Date& d);

	Day day_of_week	(const Date& d);
	Date next_Sunday	(const Date& d);
	Date next_wekday	(const Date& d);
}
