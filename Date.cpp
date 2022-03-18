#include "Date.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
	hour = 0;
	minute = 0;
	second = 0;
}

Date::Date(int day_, int month_, int year_,
	int hour_, int minute_, int second_)
{
	day = day_;
	month = month_;
	year = year_;
	hour = hour_;
	minute = minute_;
	second = second_;
}

int Date::get_day() const
{
	return day;
}

void Date::set_day(int day_)
{
	day = day_;
}

int Date::get_month() const
{
	return month;
}

void Date::set_month(int month_)
{
	month = month_;
}

int Date::get_year() const
{
	return year;
}

void Date::set_year(int year_)
{
	year = year_;
}

int Date::get_hour() const
{
	return hour;
}

void Date::set_hour(int hour_)
{
	hour = hour_;
}

int Date::get_minute() const
{
	return minute;
}

void Date::set_minute(int minute_)
{
	minute = minute_;
}

int Date::get_second() const
{
	return second;
}

void Date::set_second(int second_)
{
	second = second_;
}
