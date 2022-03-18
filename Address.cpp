#include "Address.h"

Address::Address()
{
	street = "";
	city = "";
	county = "";
	postal_code = "";
	country = "";
}

Address::Address(std::string street_, std::string city_, std::string county_,
	std::string postal_code_, std::string country_)
{
	street = street_;
	city = city_;
	county = county_;
	postal_code = postal_code_;
	country = country_;
}

std::string Address::get_street() const
{
	return street;
}

void Address::set_street(std::string street_)
{
	street = street_;
}

std::string Address::get_city() const
{
	return city;
}

void Address::set_city(std::string city_)
{
	city = city_;
}

std::string Address::get_county() const
{
	return county;
}

void Address::set_county(std::string county_)
{
	county = county_;
}

std::string Address::get_postal_code() const
{
	return postal_code;
}

void Address::set_postal_code(std::string postal_code_)
{
	postal_code = postal_code_;
}

std::string Address::get_country() const
{
	return country;
}

void Address::set_country(std::string country_)
{
	country = country_;
}
