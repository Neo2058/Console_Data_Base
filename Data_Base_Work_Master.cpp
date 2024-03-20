#include "Function.h"

int State_Menu;
//--------------------------------------------------------------------------------------------------
void Menu()
{
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод данных" << endl
		<< "(3) Изменение данных" << endl
		<< "(4) Добавление данных" << endl
		<< "(5) Удаление данных" << endl
		<< "(6) Сортировка данных" << endl
		<< "(7) Сохранение данных" << endl
		<< "Ваш выбор: " << endl;
	cin >> State_Menu;
}
//--------------------------------------------------------------------------------------------------
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();
	int actions;
	string file_name;

	int size = 0;
	Data *d = new Data[size];

	while (State_Menu != 0)
	{
		switch (State_Menu)
		{
		case 1:
			system("cls");

			cout << "Ввести данные вручную или считать из файла?: " << endl
				<< "(1) Ввести данные вручную" << endl
				<< "(2) Считать данные из файла на диске" << endl
				<< "(3) Считать данные из файла в корневой папке программы" << endl;
			cin >> actions;

			//system("cls");

			switch (actions)
			{
			case 1:
				Data_Entry(d, size);
				break;
			
			case 2:
				cout << "Введите название файла в формате //Имя файла.расширение";
				cin >> file_name;
				Data_Reading(d, size, file_name);
				break;

			case 3:
				Data_Reading(d, size, "Input.txt");
				break;
			}
			system("pause");
			system("cls");
			Menu();
			break;


		case 2:
			system("cls");

			if (size != 0)
				Print(d, size);
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;


		case 3:
			system("cls");

			if (size != 0)
				Data_Change(d, size);
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;


		case 4:
			system("cls");

			if (size != 0)
				Add_Data(d, size);
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

			
		case 5:
			system("cls");

			if (size != 0)
				Delete_Data(d, size);
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;


		case 6:
			system("cls");

			if (size != 0)
				Sorting_Data(d, size);
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;


		case 7:
			system("cls");

			if (size != 0)
				//Доработать по свитч
				/* cout << введите название файла;
				cin >> file_name;
				Save_Data(d, size, file_name);*/

				Save_Data(d, size, "Out.txt");
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;


		default:
			cout << "Пункт меню введен не верно!" << endl;
			system("cls");
			Menu();
		}

	}

	system("cls");
	cout << "Работа завершена!" << endl;
	system("pause");
}

