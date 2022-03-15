#ifndef CARD_H
#define CARD_H

#include <string>

#include "Date.h"
#include "Money.h"

class Card
{
public:
	enum class CardType { LISA, MASTERBART, HOMIR };
	enum class State { AVAILABLE, UNAVAILABLE };

	Card();
	Card(std::string debit_account_id_, CardType card_type_,
		std::string id_, Date validity_, Money transfer_limit_ = Money(-1));
	void rebinding(std::string debit_account_id_);
	void close();
	std::string get_debit_account() const;
	CardType get_card_type() const;
	std::string get_id() const;
	Date get_validity() const;
	Money get_transfer_limit() const;
	void set_transfer_limit(Money transfer_limit_);
	State get_state() const;
	void set_state(State state_);
private:
	std::string debit_account_id;
	CardType card_type;
	std::string id;
	Date validity;
	Money transfer_limit;
	State state;
};


#endif // !CARD_H
