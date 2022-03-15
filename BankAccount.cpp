#include "BankAccount.h"

#include <stdexcept>

BankAccount::BankAccount() {}

BankAccount::BankAccount(std::string account_id_, Address address_,
	std::string phone_number_)
{
	account_id = account_id_;
	address = address_;
	phone_number = phone_number_;
}

void BankAccount::close_debit_account_transaction(std::string id_from_,
	DebitAccount& account_to, Date date_)
{
	DebitAccount& debit_account = get_debit_account(id_from_);
	if (debit_account.get_id() == account_to.get_id())
		throw std::runtime_error("Transaction error: Two same id \
were given\n");
	Transaction transaction(debit_account, account_to,
		debit_account.get_balance(), debit_account.get_currency(), date_);

	transaction.make_transaction();

	if (transaction.get_state() != Transaction::State::COMPLETED)
		throw std::runtime_error("Transaction error: Invalid transaction \
status for closing a debit account\n");
	else
	{
		if (debit_account.get_card() != nullptr)
			debit_account.get_card()->close();
		for (int i = 0; i < debit_accounts.size(); i++)
			if (debit_accounts[i].get_id() == debit_account.get_id())
				debit_accounts.erase(debit_accounts.cbegin() + i);
	}
}

void BankAccount::close_debit_account_withdrawal(std::string id_, Date date_,
	CashOperation::Place place_, std::string place_id_, bool closing)
{
	DebitAccount& debit_account = get_debit_account(id_);

	if (place_ == CashOperation::Place::ATM &&
		debit_account.get_card() == nullptr)
		throw std::runtime_error("Cash operation error: For a withdrawal \
from ATM needs a card\n");

	CashOperation cash_operation(debit_account, date_,
		debit_account.get_balance(), place_, place_id_);
	cash_operation.withdrawal(closing);

	if (cash_operation.get_state() == CashOperation::State::CANCELED)
		throw std::runtime_error("Cash operation error: Invalid cash \
operation status for closing a debit account\n");
	else
	{
		if (debit_account.get_card() != nullptr)
			debit_account.get_card()->close();
		for (int i = 0; i < debit_accounts.size(); i++)
			if (debit_accounts[i].get_id() == debit_account.get_id())
				debit_accounts.erase(debit_accounts.cbegin() + i);
	}
}

std::string BankAccount::get_phone_number() const
{
	return phone_number;
}

void BankAccount::set_phone_number(std::string phone_number_)
{
	phone_number = phone_number_;
}

std::string BankAccount::get_account_id() const
{
	return account_id;
}

Address BankAccount::get_address() const
{
	return address;
}

void BankAccount::set_address(Address address_)
{
	address = address_;
}

DebitAccount& BankAccount::get_debit_account(std::string id_)
{
	if (debit_accounts.size() == 0)
		throw std::runtime_error("Debit account error: List of \
debit accounts is empty\n");

	for (int i = 0; i < debit_accounts.size(); i++)
		if (debit_accounts[i].get_id() == id_)
			return debit_accounts[i];

	throw std::runtime_error("Debit account error: There is no such \
identifier in the list of debit accounts\n");
}

void BankAccount::set_debit_account(std::string id_,
	DebitAccount::Currency currency_, Money balance_,
	Money withdrawal_limit_)
{
	bool debit_account_used = false;

	for (int i = 0; i < debit_accounts.size(); i++)
		if (debit_accounts[i].get_id() == id_)
			throw std::runtime_error("Debit account error: Such id \
already used\n");

	debit_accounts.push_back(DebitAccount(id_, currency_, balance_,
		withdrawal_limit_));
}

std::vector<DebitAccount> BankAccount::get_debit_accounts() const
{
	return debit_accounts;
}
