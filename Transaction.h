#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Date.h"
#include "Money.h"
#include "DebitAccount.h"

class Transaction
{
public:
	enum class State { FOR_PROCESSING, BEING_PROCESSED,
		COMPLETED, CANCELED };

	Transaction(DebitAccount& account_from_direct_,
		DebitAccount& account_to_direct_, Money amount_,
		DebitAccount::Currency currency_, Date date_);
	void make_transaction();
	DebitAccount get_account_from_copy() const;
	DebitAccount get_account_to_copy() const;
	Money get_amount() const;
	DebitAccount::Currency get_currency() const;
	Date get_date() const;
	State get_state() const;
private:
	DebitAccount& account_from_direct;
	DebitAccount& account_to_direct;
	DebitAccount account_from_copy;
	DebitAccount account_to_copy;
	Money amount;
	DebitAccount::Currency currency;
	Date date;
	State state;
};

#endif // !TRANSACTION_H
