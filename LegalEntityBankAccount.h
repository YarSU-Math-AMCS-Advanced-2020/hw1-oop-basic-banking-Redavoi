#ifndef LEGALENTITYBANKACCOUNT_H
#define LEGALENTITYBANKACCOUNT_H

#include <string>

#include "Date.h"
#include "Address.h"
#include "BankAccount.h"

class LegalEntityBankAccount : public BankAccount
{
public:
	LegalEntityBankAccount(std::string name_, Date estabilishing_date_,
		std::string TIN_, Address address_, std::string account_id_,
		std::string phone_number_);
	std::string get_name() const;
	void set_name(std::string name_);
	Date get_estabilishing_date() const;
	std::string get_TIN() const;
private:
	std::string name;
	Date estabilishing_date;
	std::string TIN;
};

#endif // !LEGALENTITYBANKACCOUNT_H
