#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
	Address();
	Address(std::string street_, std::string city_, std::string county_,
		std::string postal_code_, std::string country_);
	std::string get_street() const;
	void set_street(std::string street_);
	std::string get_city() const;
	void set_city(std::string city_);
	std::string get_county() const;
	void set_county(std::string county_);
	std::string get_postal_code() const;
	void set_postal_code(std::string postal_code_);
	std::string get_country() const;
	void set_country(std::string country_);
private:
	std::string street;
	std::string city;
	std::string county;
	std::string postal_code;
	std::string country;
};


#endif // !ADDRESS_H
