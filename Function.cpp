#include "Function.h"

//------------------------------------------------------------------------------------------------
void Data_Entry(Data *(&d), int & n)
{
	Initials initials;
	Date date;
	Address address;

	cout << " Введите размер массива: ";
	cin >> n;

	d = new Data[n];

	for (size_t i = 0; i < n; i++)
	{
		cout << "Введите ФИО: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;
	
		cout << "Введите Дату: ";
		cin >> date.day >> date.month >> date.year;
		
		cout << "Введите Адрес: ";
		cin >> address.city >> address.home;

		d[i].Data_Entry(initials, date, address);

		cout << "Данные успешно внесены!" << endl;
		system("pause");
		system("cls");
	}
}
//------------------------------------------------------------------------------------------------
void Data_Reading(Data *(&d), int & n, string file_name)
{
	ifstream reading(file_name);

	if (reading)
	{
		Initials initials;
		Date date;
		Address address;

		reading >> n;

		d = new Data[n];

		for (size_t i = 0; i < n; i++)
		{
			reading >> initials.surname >> initials.name >> initials.patrinymic;
			reading >> date.day >> date.month >> date.year;
			reading >> address.city >> address.home;

			d[i].Data_Entry(initials, date, address);
		}

		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
}
//------------------------------------------------------------------------------------------------
void Print(Data * d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Данные № " << i + 1 << endl;

		d[i].Print();
		cout << "_________________________________________________________________\n";
	}
}
//------------------------------------------------------------------------------------------------
void Data_Change(Data * d, int n)
{
	Initials initials;
	Date date;
	Address address;
	int count;

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> count;
	count--;

	if (count >= 0 && count < n)
	{
		cout << "Введите новую ФИО: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;

		cout << "Введите новую дату: ";
		cin >> date.day >> date.month >> date.year;

		cout << "Введите новый Адрес: ";
		cin >> address.city >> address.home;

		d[count].Data_Entry(initials, date, address);
	}
	else
		cout << "Номер введен не верно!" << endl;
}
//------------------------------------------------------------------------------------------------
void Copy(Data * d_n, Data * d_o, int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}
//------------------------------------------------------------------------------------------------
void Add_Data(Data *(&d), int & n)
{
	Initials initials;
	Date date;
	Address address;
	Data *buf = new Data[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "Введите новую ФИО: ";
	cin >> initials.surname >> initials.name >> initials.patrinymic;

	cout << "Введите новую дату: ";
	cin >> date.day >> date.month >> date.year;

	cout << "Введите новый Адрес: ";
	cin >> address.city >> address.home;

	d[size].Data_Entry(initials, date, address);

	cout << "Данные добавлены!" << endl;

	delete[] buf;

}
//------------------------------------------------------------------------------------------------
void Delete_Data(Data *(&d), int & n)
{
	int count;
	Data *buf = new Data[n];

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> count;
	count--;

	if (count >= 0 && count < n)
	{
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Data[n];

		for (int i = 0; i <= n; i++)
		{
			if (i != count)
			{
				d[q] = buf[i];
				q++;
			}

		}
		cout << " Данные удалены!" << endl;
	}
	else
		cout << "Номер введен не верно!" << endl;

	delete[] buf;
}
//------------------------------------------------------------------------------------------------
void Sorting_Data(Data * d, int & n)
{
	Data buf;
	int num_of_sorted = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (d[i].Get_Initials().surname > d[j].Get_Initials().surname)
			{
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				num_of_sorted++;
			}
		}
	}

	cout << "Данные отсортированы!\nКоличество сортировок: " << num_of_sorted << endl;
}
//------------------------------------------------------------------------------------------------
void Save_Data(Data * d, int n, string file_name)
{
	ofstream record(file_name);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i].Get_Initials().surname << " " << d[i].Get_Initials().name << " " << d[i].Get_Initials().patrinymic << endl;
			record << d[i].Get_Date().day << " " << d[i].Get_Date().month << " " << d[i].Get_Date().year << endl;
			record << d[i].Get_Address().city << " " << d[i].Get_Address().home;

			if (i < n - 1)
				record << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	cout << "Данные сохранены в файл: " << file_name << endl;

	record.close();
}
//------------------------------------------------------------------------------------------------