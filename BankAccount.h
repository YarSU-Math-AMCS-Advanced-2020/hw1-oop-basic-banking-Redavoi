#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>

#include "Address.h"
#include "Money.h"
#include "Date.h"
#include "Card.h"
#include "DebitAccount.h"
#include "CashOperation.h"
#include "Transaction.h"

class BankAccount
{
public:
	void close_debit_account_transaction(std::string id_,
		DebitAccount& account_to, Date date_);
	void close_debit_account_withdrawal(std::string id_, Date date_,
		CashOperation::Place place_, std::string place_id_, bool closing = false);
	std::string get_phone_number() const;
	void set_phone_number(std::string phone_number_);
	std::string get_account_id() const;
	Address get_address() const;
	void set_address(Address address_);
	DebitAccount& get_debit_account(std::string id_);
	void set_debit_account(std::string id_, DebitAccount::Currency currency_,
		Money balance_, Money withdrawal_limit_ = Money(-1));
	std::vector<DebitAccount> get_debit_accounts() const;
protected:
	BankAccount();
	BankAccount(std::string account_id_, Address address_,
		std::string phone_number_);
private:
	std::string phone_number;
	std::string account_id;
	Address address;
	std::vector<DebitAccount> debit_accounts;
};


#endif // !BANKACCOUNT_H
