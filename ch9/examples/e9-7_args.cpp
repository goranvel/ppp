#include <iostream>

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, avg, sep, oct, nov, dec
};

class Date {
      int y, d;
		Month m;
   public :
      class Invalid {};
      Date (int yy, Month mm, int dd) : y (yy), m (mm), d (dd) {
         if (!is_valid())
            throw Invalid();
      }

      void add_day (int n);
		Month month () {
         return m;
      }
      int day () {
         return d;
      }
      int year () {
         return y;
      }

//		std::ostream& operator<< (std::ostream& s, const Date &d) {
		std::string getDate() {
			std::string s;
			s += std::to_string(y);
			s += "/";
			s += std::to_string(int(m));
			s += "/";
			s += std::to_string(d);
			s += "";
			return s;
		}
		

	private : // necesery here
		bool is_valid ();
      bool is_leap () {
         return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
      }
};
/* ONE WAY OF WRITTING CONSTRUCTOR
Date::Date (int yy, int mm, int dd) {
   y = yy;
   m = mm;
   d = dd;
} 

// ANOTHER WAY OF WRITTING CONSTRUCTOR 
// C++11 and up
Date::Date (int yy, int mm, int dd) : y {yy}, m {mm}, d {dd} {
}

// YET ANOTHER WAY OF WRITTING CONSTRUCTOR
Date::Date (int yy, int mm, int dd) : y (yy), m (mm), d (dd) {
}
*/
void Date::add_day (int n) {
   d += n;
}

bool Date::is_valid () {
	int mm = int (m);
   if (d <= 0 || mm <= 0 || mm > 12)
      return false;

   if (mm == 2)
      if (d > 29)
         return false;
      else if (!is_leap () && d > 28)
         return false;

   if (mm < 8)
      if (mm % 2 == 1 && d > 31)
         return false;
      else if ( mm % 2 == 0 && d > 30)
         return false;

   if (mm >= 8)
      if (mm % 2 == 1 && d > 30)
         return false;
      else if (mm % 2 == 0 && d > 31)
         return false;

   return true;
}

int main (void) {
   int d, y, mm;
	Month m;
   while (std::cin >> y >> mm >> d) {
		m = Month (mm);	
		try {
//			Date d1 (y, Month::jan, d);
			Date d1 (y, Month(mm), d);

			std::cout << d1.getDate() << "\n";
		} catch (Date::Invalid) {
			std::cerr << "Invalid input\n\n";
		}
	}

	return 0;
}
