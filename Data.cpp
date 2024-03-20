#include "Data.h"

//Data
//------------------------------------------------------------------------------------------------
Data::~Data()
{
}
//------------------------------------------------------------------------------------------------
Data::Data()
{
	initials.surname = "";
	initials.name = "";
	initials.patrinymic = "";

	date.day = 0;
	date.month = 0;
	date.year = 0;

	address.city = "";
	address.home = 0;

}
//------------------------------------------------------------------------------------------------
Data::Data(Initials initialisation, Date date, Address address)
{
	initials.surname = initialisation.surname;
	initials.name = initialisation.name;
	initials.patrinymic = initialisation.patrinymic;

	date.day = date.day;
	date.month = date.month;
	date.year = date.year;

	address.city = address.city;
	address.home = address.home;
}
//------------------------------------------------------------------------------------------------
void Data::Print()
{
	cout << "ÔÈÎ: " << initials.surname << " " << initials.name << " " << initials.patrinymic << endl;
	cout << "Äàòà: " << date.day << " " << date.month << " " << date.year << endl;
	cout << "Àäğåñ: " << address.city << " " << address.home << endl;
}
//------------------------------------------------------------------------------------------------
void Data::Data_Entry(Initials initialisation, Date date, Address address)
{
	initials.surname = initialisation.surname;
	initials.name = initialisation.name;
	initials.patrinymic = initialisation.patrinymic;

	date.day = date.day;
	date.month = date.month;
	date.year = date.year;

	address.city = address.city;
	address.home = address.home;
}
//------------------------------------------------------------------------------------------------
Data & Data::operator=(Data d_o)
{
	this->initials.surname = d_o.initials.surname;
	this->initials.name = d_o.initials.name;
	this->initials.patrinymic = d_o.initials.patrinymic;

	this->date.day = d_o.date.day;
	this->date.month = d_o.date.month;
	this->date.year = d_o.date.year;

	this->address.city = d_o.address.city;
	this->address.home = d_o.address.home;

	return *this;
}
//------------------------------------------------------------------------------------------------