#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

/*
	������:
	1. ���
	2. ���� ���������� �� ���������
	3. ��� ��� � � �������

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

//�������� ������
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