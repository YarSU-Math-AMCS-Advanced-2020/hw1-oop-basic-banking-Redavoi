#ifndef MONEY_H
#define MONEY_H

class Money
{
public:
	Money(int entier_ = 0, int floor_ = 0);
	int get_entier() const;
	void set_entier(int entier_);
	int get_floor() const;
	void set_floor(int floor_);
	friend Money operator+(const Money& left, const Money& right);
	friend Money operator-(const Money& left, const Money& right);
	friend Money operator/(const Money& left, double right);
	friend Money operator*(const Money& left, double right);
	friend bool operator==(const Money& left, const Money& right);
	friend bool operator>(const Money& left, const Money& right);
private:
	int entier = 0;
	int floor = 0;
};

#endif // !MONEY_H
