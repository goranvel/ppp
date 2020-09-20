#include <iostream>
#include <vector>

class MyClass {
		int a, b;
	public :
		void print() {
			std::cout << a << " " << b << "\n";
		}
};

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, avg, sep, oct, nov, dec
};

class Date {
      int y = 2000, d = 1;
		Month m = Month::jan;
   public :
		class Invalid {};

		Date () {
		}
		
		Date (int yy, Month mm, int dd) : y (yy), m (mm), d (dd) {
         if (!is_valid())
            throw Invalid();
      }

		Date (int yy) : y {yy} {
		}


      void add_day (int n) {
			d += n;
		}

		Month month () const {
         return m;
      }
      int day () const {
         return d;
      }
      int year () const {
         return y;
      }

//		std::ostream& operator<< (std::ostream& s, const Date &d) {
		std::string getDate() const {
			std::string s;
			s += std::to_string(y) + "/" + std::to_string(int(m)) + "/" + std::to_string(d) + "";
			return s;
		}
		
		void printDate() const {
			std::cout << getDate() << "\n";
		}

	private : // necesery here
		bool is_valid ();
      bool is_leap () {
         return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
      }
};

bool Date::is_valid () {
	int mm = int (m);
   if (d <= 0 || d > 31 || mm <= 0 || mm > 12)
      return false;

   if (mm == 2)
      if (d > 29)
         return false;
      else if (!is_leap () && d > 28)
         return false;

   if (mm < 8)
      if ( mm % 2 == 0 && d > 30)
         return false;
	else 
      if (mm % 2 == 1 && d > 30)
         return false;

   return true;
}

int main (void) {
	std::string s;
	for (int i = 0; i < s.size(); ++i)
		s[i] = toupper(s[i]);

	std::cout << s << "\n";
	std::vector <std::string> v;
	v.push_back ("bad");

	MyClass m;
	m.print();
	
	Date d{};
	d.printDate();
	
	std::vector <Date> vd (10);

	vd[0].printDate();
	vd[2].printDate();
	vd[5].printDate();

	return 0;
}

void school_year (Date d, const Date &start) {
	int a = d.day();
	int b = start.day();
	d.add_day(3);
//	start.add_day(5);

}
