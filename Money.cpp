#include "Money.h"

#include <cmath>
#include <stdexcept>

Money::Money(int entier_, int floor_)
{
	entier = entier_;
	if (floor_ > 99)
	{
		entier += floor_ / 100;
		floor_ %= 100;
	}
	floor = floor_;
}

int Money::get_entier() const
{
	return entier;
}

void Money::set_entier(int entier_)
{
	entier = entier_;
}

int Money::get_floor() const
{
	return floor;
}

void Money::set_floor(int floor_)
{
	floor = floor;
}

Money operator+(const Money& left, const Money& right)
{
	int sum_floor = left.floor + right.floor;
	int sum_entier = left.entier + right.entier;
	if (sum_floor >= 100)
	{
		sum_entier += 1;
		sum_floor %= 100;
	}
	return Money(sum_entier, sum_floor);
}

Money operator-(const Money& left, const Money& right)
{
	int sum_floor = left.floor - right.floor;
	int sum_entier = left.entier - right.entier;
	if (sum_floor < 0)
	{
		sum_entier -= 1;
		sum_floor += 100;
	}
	return Money(sum_entier, sum_floor);
}

Money operator/(const Money& left, double right)
{
	if (right == 0)
		throw std::runtime_error("Math error: Attempted to divide by Zero\n");
	double div_entier = left.entier / right;
	double div_floor = left.floor / right;
	div_floor += int(floor(div_entier * 100)) % 100;
	div_entier = floor(div_entier);
	if (div_floor > 99)
	{
		div_entier += div_floor / 100;
		div_floor = int(floor(div_floor)) % 100;
	}
	return Money(left.entier / right, left.floor / right);
}

Money operator*(const Money& left, double right)
{
	double new_entier = left.entier * right;
	double new_floor = left.floor * right;
	new_floor += int(floor(new_entier * 100)) % 100;
	new_entier = floor(new_entier);
	if (new_floor > 99)
	{
		new_entier += new_floor / 100;
		new_floor = int(floor(new_floor)) % 100;
	}
	return Money(new_entier, new_floor);
}

bool operator==(const Money& left, const Money& right)
{
	if (left.entier == right.entier && left.floor == right.floor)
		return true;
	else
		return false;
}

bool operator>(const Money& left, const Money& right)
{
	if (left.entier > right.entier)
		return true;
	else if (left.entier == right.entier && left.floor > right.floor)
		return true;
	else
		return false;
}
