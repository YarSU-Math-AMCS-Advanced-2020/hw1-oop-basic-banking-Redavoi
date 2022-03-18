#ifndef CASHOPERATION_H
#define CASHOPERATION_H

#include <string>

#include "Date.h"
#include "Money.h"
#include "DebitAccount.h"

class CashOperation
{
public:
	enum class State { COMPLETED, CANCELED };
	enum class TypeOperation { DEPOSIT, WITHDRAWAL };
	enum class Place { BANK, ATM };

	CashOperation(DebitAccount& debit_account_direct_, Date date_,
		Money amount_, Place place_, std::string place_id_);
	void withdrawal(bool closing);
	void deposit();
	DebitAccount get_debit_account_copy() const;
	Date get_date() const;
	Money get_amount() const;
	Place get_place() const;
	std::string  get_place_id() const;
	State get_state() const;
	TypeOperation get_type_operation() const;
private:
	DebitAccount& debit_account_direct;
	DebitAccount debit_account_copy;
	Date date;
	Money amount;
	Place place;
	std::string place_id;
	State state;
	TypeOperation type_operation;
};

#endif // !CASHOPERATION_H
