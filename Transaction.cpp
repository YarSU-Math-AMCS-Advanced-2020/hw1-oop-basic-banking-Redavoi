#include "Transaction.h"

Transaction::Transaction(DebitAccount& account_from_direct_,
	DebitAccount& account_to_direct_, Money amount_,
	DebitAccount::Currency currency_,
	Date date_) :account_from_direct(account_from_direct_), \
	account_to_direct(account_to_direct_)
{
	account_from_copy = DebitAccount(account_from_direct_);
	account_to_copy = DebitAccount(account_to_direct_);
	amount = amount_;
	currency = currency_;
	date = date_;
	state = State::FOR_PROCESSING;
}

void Transaction::make_transaction()
{
	if (account_from_direct.get_currency() !=
		account_to_direct.get_currency() ||
		amount > account_from_direct.get_balance() ||
		account_to_direct.get_currency() != currency ||
		account_from_direct.get_card() == nullptr ||
		account_to_direct.get_card() == nullptr)
		state = State::CANCELED;
	else
	{
		state = State::BEING_PROCESSED;
		account_from_direct.set_balance(account_from_direct.get_balance() -
			amount);
		account_from_copy.set_balance(account_from_direct.get_balance());
		account_to_direct.set_balance(account_to_direct.get_balance() +
			amount);
		account_to_copy.set_balance(account_to_direct.get_balance());
		state = State::COMPLETED;
	}
}

DebitAccount Transaction::get_account_from_copy() const
{
	return account_from_copy;
}

DebitAccount Transaction::get_account_to_copy() const
{
	return account_to_copy;
}

Money Transaction::get_amount() const
{
	return amount;
}

DebitAccount::Currency Transaction::get_currency() const
{
	return currency;
}

Date Transaction::get_date() const
{
	return date;
}

Transaction::State Transaction::get_state() const
{
	return state;
}
