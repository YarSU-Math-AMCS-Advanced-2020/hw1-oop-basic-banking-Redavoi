#include "CashOperation.h"

CashOperation::CashOperation(DebitAccount& debit_account_direct_, Date date_,
	Money amount_, Place place_,
	std::string place_id_) :debit_account_direct(debit_account_direct_)
{
	debit_account_copy = DebitAccount(debit_account_direct_);
	date = date_;
	amount = amount_;
	place = place_;
	place_id = place_id_;
}

void CashOperation::withdrawal(bool closing)
{
	type_operation = TypeOperation::WITHDRAWAL;

	if (amount > debit_account_direct.get_withdrawal_limit() && !closing ||
		amount > debit_account_direct.get_balance() || place == Place::ATM &&
		debit_account_copy.get_card() == nullptr)
		state = State::CANCELED;
	else
	{
		debit_account_direct.set_balance(debit_account_direct.get_balance() -
			amount);
		debit_account_copy.set_balance(debit_account_direct.get_balance());
		state = State::COMPLETED;
	}
}

void CashOperation::deposit()
{
	type_operation = TypeOperation::DEPOSIT;

	if (place == Place::ATM && debit_account_copy.get_card() == nullptr)
		state = State::CANCELED;
	else
	{
		debit_account_direct.set_balance(debit_account_direct.get_balance() +
			amount);
		debit_account_copy.set_balance(debit_account_direct.get_balance());
		state = State::COMPLETED;
	}
}

DebitAccount CashOperation::get_debit_account_copy() const
{
	return debit_account_copy;
}

Date CashOperation::get_date() const
{
	return date;
}

Money CashOperation::get_amount() const
{
	return amount;
}

CashOperation::Place CashOperation::get_place() const
{
	return place;
}

std::string  CashOperation::get_place_id() const
{
	return place_id;
}

CashOperation::State CashOperation::get_state() const
{
	return state;
}

CashOperation::TypeOperation CashOperation::get_type_operation() const
{
	return type_operation;
}
