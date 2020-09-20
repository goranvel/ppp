namespace Chrono {
	enum class Month {
		jan = 1,	
		feb,	mar,	apr,	may,	jun,
		jul,	aug,	sep,	oct,	nov,	
		dec
	};

	enum class Day {
		sunday = 0, 
		monday, tuesday, wednessday, 
		thursday, firday,
		saturday
	};

	std::vector <int> days {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leapyear(int i);

	class Date {
			long int d; // y, d;
			int zero; 
//			Month m;
		public :
			class Invalid {}; // exception class

			Date (int y, Month m, int d);		// check for valid date and time
			Date ();	// default constructor
			
			//  non modiffying operator 
			//	 day of the month
			int day () const {
				int leaps = (year() - zero)/4;
				int dd = d - leaps * 366 - (year() - zero - leaps) * 365;
				int i = 0;
				for (; dd > days[i]; dd -= days[i], ++i);
	
				return dd;
			}

			Month month () const {
				int leaps = (year() - zero)/4;
				int dd = d - leaps * 366 - (year() - zero - leaps) * 365;
				int i = 0;
				for (; dd > days[i]; dd -= days[i], ++i);
			
				return Month(i + 1);
			}

			int year () const {
				long dd = d;
				int i = zero;
				for (; dd >= 365 + (leapyear(i) ? 1 : 0); ++i, dd -= 365 - (leapyear(i) ? 1 : 0));

				return i;
			} 
			
			// modifying operation
			void add_day (int n);
			void add_month(int n);
			void add_year(int n);
	};

	bool is_date	(int y, Month m, int d);
	bool leapyear	(int y);

	bool operator == (const Date& a, const Date& b);
	bool operator != (const Date& a, const Date& b);

	std::ostream& operator<< (std::ostream& os, const Date& d);
	std::istream& operator>> (std::ostream& is, Date& d);

	Day day_of_week	(const Date& d);
	Date next_Sunday	(const Date& d);
	Date next_workday	(const Date& d);
}
