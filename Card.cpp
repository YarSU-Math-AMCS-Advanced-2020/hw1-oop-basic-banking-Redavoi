#include "Card.h"

Card::Card()
{
	state = State::UNAVAILABLE;
	debit_account_id = "";
}

Card::Card(std::string debit_account_id_, CardType card_type_,
	std::string id_, Date validity_, Money transfer_limit_)
{
	debit_account_id = debit_account_id_;
	card_type = card_type_;
	id = id_;
	validity = validity_;
	transfer_limit = transfer_limit_;
	state = State::AVAILABLE;
}

std::string Card::get_debit_account() const
{
	return debit_account_id;
}

void Card::set_debit_account_id(std::string id_)
{
	debit_account_id = id_;
}

Card::CardType Card::get_card_type() const
{
	return card_type;
}

std::string Card::get_id() const
{
	return id;
}

Date Card::get_validity() const
{
	return validity;
}

Money Card::get_transfer_limit() const
{
	return transfer_limit;
}

void Card::set_transfer_limit(Money transfer_limit_)
{
	transfer_limit = transfer_limit_;
}

Card::State Card::get_state() const
{
	return state;
}

void Card::set_state(State state_)
{
	state = state_;
}
