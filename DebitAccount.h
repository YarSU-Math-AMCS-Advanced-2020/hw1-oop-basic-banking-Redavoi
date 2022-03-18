#ifndef DEBITACCOUNT_H
#define DEBITACCOUNT_H

#include <string>

#include "Money.h"
#include "Date.h"
#include "Card.h"

class DebitAccount
{
public:
	enum class Currency { RUB, USD, EUR };

	DebitAccount();
	DebitAccount(std::string id_, Currency currency_, Money balance_,
		Money withdrawal_limit_ = Money(-1));
	DebitAccount(const DebitAccount& debit_account_);
	void close_card();
	std::string get_id() const;
	Currency get_currency() const;
	Money get_balance() const;
	void set_balance(Money balance_);
	Money get_withdrawal_limit() const;
	void set_withdrawal_limit(Money withdrawal_limit_);
	Card* get_card() const;
	void set_card(Card* card_);
private:
	std::string id;
	Currency currency;
	Money balance;
	Money withdrawal_limit;
	Card* card;
};

#endif // !DEBITACCOUNT_H
