#include <iostream>

class Date {
	int year_;
	int month_;		// 1 부터 12 까지.
	int day_;	  // 1 부터 31 까지.
	int monthDate[12] = {31, 28, 31,30,31,30,31,31,30,31,30,31};

	bool IsLeapYear(int year) {		//윤년
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0)
					return true;
				else
					return false;
			}
			else
				return true;
		}
		else
			return false;
	}

public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	};

	void AddDay(int inc) {
		day_ += inc;

		while (day_ > monthDate[month_ - 1]) {
			if (month_ == 2 && IsLeapYear(year_)) {
				if (day_ > 29) {
					day_ -= 29;
					AddMonth(1);
				}
				else {
					break;
				}
			}
			else {
				day_ -= monthDate[month_ - 1];
				AddMonth(1);
			}
		}
	};

	void AddMonth(int inc) {
		month_ += inc;

		while (month_ > 12) {
			month_ -= 12;
			year_++;
		}
	};

	void AddYear(int inc) {
		year_ += inc;
	};

	void ShowDate() {
		std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
	};
};

int main() {
	Date date;
	date.SetDate(1999, 1, 8);
	date.AddDay(1000);
	date.ShowDate();
	return 0;
}