#include <iostream>
#include <vector>
#include "Address.h"
#include "Card.h"
#include "CashOperation.h"
#include "Date.h"
#include "DebitAccount.h"
#include "LegalEntityBankAccount.h"
#include "Money.h"
#include "PersonalBankAccount.h"
#include "Transaction.h"

void output_card(Card* c)
{
	if (c->get_card_type() == Card::CardType::HOMIR)
		std::cout << '\t' << "Card type: " << "HOMIR" << '\n';
	else if (c->get_card_type() == Card::CardType::LISA)
		std::cout << '\t' << "Card type: " << "LISA" << '\n';
	else if (c->get_card_type() == Card::CardType::MASTERBART)
		std::cout << '\t' << "Card type: " << "MASTERBART" << '\n';

	std::cout << '\t' << "Debit account id: " << \
		c->get_debit_account() << '\n';
	std::cout << '\t' << "Id: " << c->get_id() << '\n';

	if (c->get_state() == Card::State::AVAILABLE)
		std::cout << '\t' << "Card state: " << "AVAILABLE" << '\n';
	else if (c->get_state() == Card::State::UNAVAILABLE)
		std::cout << '\t' << "Card state: " << "UNAVAILABLE" << '\n';

	std::cout << '\t' << "Transfer limit: " << \
		c->get_transfer_limit().get_entier() << ' '\
		<< c->get_transfer_limit().get_floor() << '\n';
	std::cout << "Validity: " << c->get_validity().get_day() << ' ' << \
		c->get_validity().get_month() << ' ' << \
		c->get_validity().get_year() << '\n';
}

void output_debit_acc(DebitAccount dba)
{
	std::cout << '\t' << "Balance: " << dba.get_balance().get_entier() << \
		' ' << dba.get_balance().get_floor() << '\n';

	if (dba.get_currency() == DebitAccount::Currency::RUB)
		std::cout << '\t' << "Currency: " << "RUB" << '\n';
	else if (dba.get_currency() == DebitAccount::Currency::EUR)
		std::cout << '\t' << "Currency: " << "EUR" << '\n';
	else if (dba.get_currency() == DebitAccount::Currency::USD)
		std::cout << '\t' << "Currency: " << "USD" << '\n';

	std::cout << "Id: " << dba.get_id() << '\n';
	std::cout << "Withdrawal limit: " << \
		dba.get_withdrawal_limit().get_entier() << ' '\
		<< dba.get_withdrawal_limit().get_floor() << '\n';
	std::cout << "Card: " << '\n';

	if (dba.get_card() != nullptr)
		output_card(dba.get_card());
}

void output_personal(const PersonalBankAccount& pba)
{
	std::cout << "Surname: " << pba.get_surname() << '\n';
	std::cout << "Name: " << pba.get_name() << '\n';
	std::cout << "Birth date: "  << pba.get_birth_date().get_day() << ' ' \
		<< pba.get_birth_date().get_month() << ' ' \
		<< pba.get_birth_date().get_year() << '\n';

	if (pba.get_sex() == PersonalBankAccount::Sex::MALE)
		std::cout << "Sex: " << "male" << '\n';
	else if (pba.get_sex() == PersonalBankAccount::Sex::FEMALE)
		std::cout << "Sex: " << "female" << '\n';
	else
		std::cout << "Sex: " << "another" << '\n';

	std::cout << "Passport: " << pba.get_passport() << '\n';
	std::cout << "Account id: " << pba.get_account_id() << '\n';
	std::cout << "Address: " << '\n';
	std::cout << '\t' << "Street: " << pba.get_address().get_street() << '\n';
	std::cout << '\t' << "City: " << pba.get_address().get_city() << '\n';
	std::cout << '\t' << "County: " << pba.get_address().get_county() << '\n';
	std::cout << '\t' << "Postal code: " << \
		pba.get_address().get_postal_code() << '\n';
	std::cout << '\t' << "Country: " << \
		pba.get_address().get_country() << '\n';
	std::cout << "Phone number: " << pba.get_phone_number() << '\n';
	std::cout << "Patronymic: " << pba.get_patronymic() << '\n';
	std::cout << "Debit account: " << '\n';

	std::vector<DebitAccount> dba = pba.get_debit_accounts();
	for (int i = 0; i < dba.size(); i++)
		output_debit_acc(dba[i]);
	std::cout << '\n' << '\n' << '\n';
}

void output_legal(const LegalEntityBankAccount& leba)
{
	std::cout << "Name: " << leba.get_name() << '\n';
	std::cout << "Estabilishing date: " << \
		leba.get_estabilishing_date().get_day() << ' ' \
		<< leba.get_estabilishing_date().get_month() << ' ' \
		<< leba.get_estabilishing_date().get_year() << '\n';
	std::cout << "TIN: " << leba.get_TIN() << '\n';
	std::cout << "Address: " << '\n';
	std::cout << '\t' << "Street: " << \
		leba.get_address().get_street() << '\n';
	std::cout << '\t' << "City: " << leba.get_address().get_city() << '\n';
	std::cout << '\t' << "County: " << \
		leba.get_address().get_county() << '\n';
	std::cout << '\t' << "Postal code: " << \
		leba.get_address().get_postal_code() << '\n';
	std::cout << '\t' << "Country: " << \
		leba.get_address().get_country() << '\n';
	std::cout << "Account id: " << leba.get_account_id() << '\n';
	std::cout << "Phone number: " << leba.get_phone_number() << '\n';
	std::cout << "Debit account: " << '\n';

	std::vector<DebitAccount> dba = leba.get_debit_accounts();
	for (int i = 0; i < dba.size(); i++)
		output_debit_acc(dba[i]);
	std::cout << '\n' << '\n' << '\n';
}

int main()
{
	PersonalBankAccount pba1("surname1", "name1", Date(1, 1, 2001),
		PersonalBankAccount::Sex::MALE, "123456 7890", "112233",
		Address("street1", "city1", "county1", "200019", "country1"),
		"79501235678");
	std::cout << "----------Output pba1 information----------" << \
		'\n' << '\n';
	output_personal(pba1);

	PersonalBankAccount pba2("surname2", "name2", Date(2, 2, 2002),
		PersonalBankAccount::Sex::FEMALE, "098765 4321", "332211",
		Address("street2", "city2", "county2", "910002", "country2"),
		"795087654321", "patronymic2");
	std::cout << "----------Output pba2 information----------" << \
		'\n' << '\n';
	output_personal(pba2);

	LegalEntityBankAccount leba1("name3", Date(3, 3, 2003), "123",
		Address("street3", "city3", "county3", "400012", "country3"),
		"788231", "79501122349");
	std::cout << "----------Output leba1 information----------" << \
		'\n' << '\n';
	output_legal(leba1);

	std::cout << "----------Changing pba1 information----------" << \
		'\n' << '\n';
	pba1.set_name("name12");
	output_personal(pba1);

	std::cout << "----------Creating debit account leba1----------" << '\n';
	leba1.set_debit_account("id999", DebitAccount::Currency::RUB,
		Money(1000), 150);
	std::cout << "----------Creating debit account pba1----------" << '\n';
	pba1.set_debit_account("id888", DebitAccount::Currency::RUB,
		Money(0), 500);
	std::cout << "----------Creating debit account pba2----------" << \
		'\n' << '\n';
	pba2.set_debit_account("id123", DebitAccount::Currency::RUB, Money(333));
	output_legal(leba1);
	output_personal(pba1);
	output_personal(pba2);

	std::cout << "----------Creating debit account pba1----------" << \
		'\n' << '\n';
	pba1.set_debit_account("id777", DebitAccount::Currency::RUB,
		Money(651), 500);
	output_personal(pba1);

	std::cout << "----------Closing debit account pba1----------" << \
		'\n' << '\n';
	pba1.close_debit_account_withdrawal("id777", Date(5, 5, 2007),
		CashOperation::Place::BANK, "placeid111", true);
	output_personal(pba1);

	std::cout << "----------Creating card pba1----------" << '\n' << '\n';
	Card c1("id888", Card::CardType::LISA, "id90", Date(6, 2, 2025));
	pba1.get_debit_account("id888").set_card(&c1);
	output_personal(pba1);

	std::cout << "----------Creating card pba2----------" << '\n' << '\n';
	Card c2("id888", Card::CardType::MASTERBART, "id909", Date(16, 12, 2125));
	pba2.get_debit_account("id123").set_card(&c2);
	output_personal(pba2);

	std::cout << "----------Closin debit account pba2 through transaction \
to pba1----------" << '\n' << '\n';
	pba2.close_debit_account_transaction("id123",
		pba1.get_debit_account("id888"), Date(6, 6, 2008));
	output_personal(pba2);
	output_personal(pba1);

	std::cout << "----------Creating debit account pba1----------" << \
		'\n' << '\n';
	pba1.get_debit_account("id888").set_withdrawal_limit(Money(88));
	output_personal(pba1);

	std::cout << "----------Creating card leba1----------" << '\n' << '\n';
	Card card3("id999", Card::CardType::HOMIR, "id4", Date(9, 9, 2020));
	leba1.get_debit_account("id999").set_card(&card3);
	output_legal(leba1);

	std::cout << "----------Set transfer limit card leba1----------" << \
		'\n' << '\n';
	leba1.get_debit_account("id999").get_card()->set_transfer_limit(Money(200));
	output_legal(leba1);

	std::cout << "----------Making transaction between leba1 \
and pba1----------" << '\n' << '\n';
	Transaction t1(leba1.get_debit_account("id999"),
		pba1.get_debit_account("id888"), Money(111), 
		DebitAccount::Currency::RUB, Date(7, 7, 2005));
	t1.make_transaction();
	output_legal(leba1);
	output_personal(pba1);

	std::cout << "----------Withdrawal cash from leba1----------" << \
		'\n' << '\n';
	CashOperation co1(leba1.get_debit_account("id999"), Date(11, 11, 2011),
		Money(150), CashOperation::Place::ATM, "209");
	co1.withdrawal(false);
	output_legal(leba1);

	std::cout << "----------Deposit cash to pba1----------" << '\n' << '\n';
	CashOperation co2(pba1.get_debit_account("id888"), Date(12, 12, 2012),
		Money(80), CashOperation::Place::ATM, "209");
	co2.deposit();
	output_personal(pba1);

	std::cout << "----------Closing card leba1----------" << '\n' << '\n';
	leba1.get_debit_account("id999").close_card();
	output_legal(leba1);

	std::cout << "----------Creating debit account pba1----------" << '\n';
	pba1.set_debit_account("id0", DebitAccount::Currency::EUR, Money(3));
	std::cout << "----------Rebinding card pba1----------" << '\n' << '\n';
	pba1.rebinding_card(&c1, "id888", "id0");
	output_personal(pba1);

	std::cout << "----------General output leba1, pba1, pba2----------" << \
		'\n' << '\n';
	output_legal(leba1);
	output_personal(pba1);
	output_personal(pba2);

	std::cout << "----------Closing debit account leba1----------" << '\n';
	leba1.close_debit_account_withdrawal("id999", Date(1, 12, 2112),
		CashOperation::Place::BANK, "2", true);
	std::cout << "----------Closing debit account pba1----------" << '\n';
	pba1.close_debit_account_withdrawal("id888", Date(8, 8, 2098),\
		CashOperation::Place::BANK, "1", true);
	std::cout << "----------Closing debit account pba1----------" << '\n' << '\n';
	pba1.close_debit_account_withdrawal("id0", Date(8, 8, 2098),\
		CashOperation::Place::BANK, "3", true);

	output_legal(leba1);
	output_personal(pba1);
	output_personal(pba2);

	return 0;
}