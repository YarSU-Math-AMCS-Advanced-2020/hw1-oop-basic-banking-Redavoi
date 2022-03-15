#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date();
	// Òo validation check
	Date(int day_, int month_, int year_,
		int hour_ = 0, int minute_ = 0, int second_ = 0);
	int get_day() const;
	void set_day(int day_);
	int get_month() const;
	void set_month(int month_);
	int get_year() const;
	void set_year(int year_);
	int get_hour() const;
	void set_hour(int hour_);
	int get_minute() const;
	void set_minute(int minute_);
	int get_second() const;
	void set_second(int second_);
private:
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int second;
};


#endif // !DATE_H
