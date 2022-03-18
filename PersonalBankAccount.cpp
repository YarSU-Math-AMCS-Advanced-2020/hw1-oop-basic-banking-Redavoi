#include "PersonalBankAccount.h"

#include <stdexcept>

PersonalBankAccount::PersonalBankAccount(std::string surname_,
	std::string name_, Date birth_date_, Sex sex_, std::string passport_,
	std::string account_id_, Address address_, std::string phone_number_,
	std::string patronymic_) :BankAccount::BankAccount(account_id_,
		address_, phone_number_)
{
	surname = surname_;
	name = name_;
	birth_date = birth_date_;
	sex = sex_;
	passport = passport_;
	patronymic = patronymic_;
}

bool PersonalBankAccount::has_patronymic() const
{
	if (patronymic == "")
		return false;
	else
		return true;
}

std::string PersonalBankAccount::reduced_name() const
{
	return name[0] + ". " + surname;
}

std::string PersonalBankAccount::get_surname() const
{
	return surname;
}

void PersonalBankAccount::set_surname(std::string surname_)
{
	surname = surname_;
}

std::string PersonalBankAccount::get_name() const
{
	return name;
}

void PersonalBankAccount::set_name(std::string name_)
{
	name = name_;
}

Date PersonalBankAccount::get_birth_date() const
{
	return birth_date;
}

PersonalBankAccount::Sex PersonalBankAccount::get_sex() const
{
	return sex;
}

void PersonalBankAccount::set_sex(PersonalBankAccount::Sex sex_)
{
	sex = sex_;
}

std::string PersonalBankAccount::get_passport() const
{
	return passport;
}

void PersonalBankAccount::set_passport(std::string passport_)
{
	passport = passport_;
}

std::string PersonalBankAccount::get_patronymic() const
{
	return patronymic;
}
