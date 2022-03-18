#include "LegalEntityBankAccount.h"

LegalEntityBankAccount::LegalEntityBankAccount(std::string name_,
	Date estabilishing_date_, std::string TIN_, Address address_,
	std::string account_id_,
	std::string phone_number_) :BankAccount(account_id_, address_,
		phone_number_)
{
	name = name_;
	estabilishing_date = estabilishing_date_;
	TIN = TIN_;
}

std::string LegalEntityBankAccount::get_name() const
{
	return name;
}

void LegalEntityBankAccount::set_name(std::string name_)
{
	name = name_;
}

Date LegalEntityBankAccount::get_estabilishing_date() const
{
	return estabilishing_date;
}

std::string LegalEntityBankAccount::get_TIN() const
{
	return TIN;
}
