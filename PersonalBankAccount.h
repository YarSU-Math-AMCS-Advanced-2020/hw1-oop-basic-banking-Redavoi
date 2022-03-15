#ifndef PERSONALBANKACCOUNT_H
#define PERSONALBANKACCOUNT_H

#include <string>

#include "Date.h"
#include "Address.h"
#include "BankAccount.h"

class PersonalBankAccount : public BankAccount
{
public:
	enum class Sex { MALE, FEMALE, ANOTHER };

	PersonalBankAccount(std::string surname_, std::string name_,
		Date birth_date_, Sex sex_, std::string passport_,
		std::string account_id_, Address address_,
		std::string phone_number_, std::string patronymic_ = "");
	bool has_patronymic() const;
	std::string reduced_name() const;
	std::string get_surname() const;
	void set_surname(std::string surname_);
	std::string get_name() const;
	void set_name(std::string name_);
	Date get_birth_date() const;
	Sex get_sex() const;
	void set_sex(Sex sex_);
	std::string get_passport() const;
	void set_passport(std::string passport_);
	std::string get_patronymic() const;
private:
	std::string surname;
	std::string name;
	Date birth_date;
	Sex sex;
	std::string passport;
	std::string patronymic;
};



#endif // !PERSONALBANKACCOUNT_H
