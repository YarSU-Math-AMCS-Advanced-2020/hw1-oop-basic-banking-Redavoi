#include "DebitAccount.h"

DebitAccount::DebitAccount() {}

DebitAccount::DebitAccount(std::string id_, Currency currency_,
	Money balance_, Money withdrawal_limit_)
{
	id = id_;
	currency = currency_;
	balance = balance_;
	withdrawal_limit = withdrawal_limit_;
	card = nullptr;
}

DebitAccount::DebitAccount(const DebitAccount& debit_account_)
{
	id = debit_account_.id;
	withdrawal_limit = debit_account_.withdrawal_limit;
	currency = debit_account_.currency;
	balance = debit_account_.balance;
	card = debit_account_.get_card();
}

std::string DebitAccount::get_id() const
{
	return id;
}

DebitAccount::Currency DebitAccount::get_currency() const
{
	return currency;
}

Money DebitAccount::get_balance() const
{
	return balance;
}

void DebitAccount::set_balance(Money balance_)
{
	balance = balance_;
}

Money DebitAccount::get_withdrawal_limit() const
{
	return withdrawal_limit;
}

void DebitAccount::set_withdrawal_limit(Money withdrawal_limit_)
{
	withdrawal_limit = withdrawal_limit_;
}

Card* DebitAccount::get_card() const
{
	return card;
}

void DebitAccount::set_card(Card* card_)
{
	card = card_;
	if (card->get_transfer_limit() == Money(-1))
		card->set_transfer_limit(withdrawal_limit);
	card->set_state(Card::State::AVAILABLE);
}
