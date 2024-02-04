#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

/*
	Данные:
	1. ФИО
	2. Дата постановки на должность
	3. ФИО ТЧМ и № Колонны

*/

struct Initials
{
	string surname, name, patrinymic;
};

struct Date
{
	int day, month, year;
};

struct Address
{
	string city;
	int home;
};

//Прототип класса
class Data
{
private:
	Initials initials;
	Date date;
	Address address;

public:
	Data();
	Data(Initials initialisation, Date date, Address address);
	~Data();

	void Print();
	void Data_Entry(Initials initialisation, Date date, Address address);

	Initials Get_Initials() { return initials; };
	Date Get_Date() { return date; };
	Address Get_Address() { return address; };

	Data& operator = (Data d_o);
};