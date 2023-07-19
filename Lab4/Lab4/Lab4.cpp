#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

struct tourist
{
public:
	string passport;
	int date_in;
	int date_ot;
	string type;
	string fio;
};

void input();
void output();
void find();
void outEl();
void del();
void write();
tourist tr[4];

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int choice;
	do
	{
		cout << "1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по фамилии\n";
		cout << "4.Просмотр определённых данных гостей\n";
		cout << "5.Удаление данных\n";
		cout << "6.Записать данные в файл\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
			case 1: input();  break;
			case 2: output(); break;
			case 3: find(); break;
			case 4: outEl(); break;
			case 5: del(); break;
			case 6: write(); break;
			case 0: exit(0);  break;
		}
	} while (choice != 0);

}

void input()
{
	ofstream fout;
	fout.open("FILE.txt");

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << " Гость\n";
			cout << "Введите паспотрные данные " << i + 1 << "-ого гостя: ";
			cin >> tr[i].passport;
			cout << "Введите дату приезда " << i + 1 << "-ого гостя: ";
			cin >> tr[i].date_in;
			cout << "Введите дату отъезда " << i + 1 << "-ого гостя: ";
			cin >> tr[i].date_ot;
			cout << "Введите тип размещения (люкс, одноместный, двухместный, трехместный, апартаменты) " << i + 1 << "-ого гостя: ";
			cin >> tr[i].type;
			cout << "Введите фамилию " << i + 1 << "-ого гостя: ";
			cin >> tr[i].fio;

			cout << "\n";
			fout << i + 1 << " Гость" << '\n' << tr[i].passport << '\n' << tr[i].date_in << '\n' << tr[i].date_ot << '\n' << tr[i].type << '\n' << tr[i].fio << "\n\n";
	}
		fout.close();
}

void output()
{
	string str;
	ifstream fin;
	fin.open("FILE.txt");
	while (!fin.eof())
	{
		str = "";
		getline(fin, str);
		cout << str << '\n';
	}
}

void find()
{
	string fio;
	cout << "Введите фамилию: ";
	cin >> fio;
	for (int i = 0; i < 4; i++)
	{
		if (fio == tr[i].fio)
		{
			cout << i + 1 << " Гость" << '\n' << tr[i].passport << '\n' << tr[i].date_in << '\n' << tr[i].date_ot << '\n' << tr[i].type << '\n' << tr[i].fio << "\n\n";
		}
	}
}

void outEl()
{
	int visit, choice;
	do
	{
		cout << "Какие данные вы хотите посмотреть:\n";
		cout << "1.Паспортные данные\n";
		cout << "2.Дата приезда\n";
		cout << "3.Дата отъезда\n";
		cout << "4.Тип размещения\n";
		cout << "5.Фамилия\n";
		cout << "0.Выход\n";
		cin >> choice;
		if (choice == 0) return;
		cout << "Данные какго гостя вы хотите посмотреть?: ";
		cin >> visit;
		switch (choice)
		{
		case 1: cout << endl << tr[visit - 1].passport << endl;  break;
		case 2: cout << endl << tr[visit - 1].date_in << endl; break;
		case 3: cout << endl << tr[visit - 1].date_ot << endl; break;
		case 4: cout << endl << tr[visit - 1].type << endl; break;
		case 5: cout << endl << tr[visit - 1].fio << endl;  break;
		}
	} while (true);
}

void del()
{
	int visit;
	do
	{
		cout << "Данные какого гостя вы хотите удалить(выход - 0): ";
		cin >> visit;
		if (visit == 0) return;
		tr[visit - 1].passport = "";
		tr[visit - 1].date_in = NULL;
		tr[visit - 1].date_ot = NULL;
		tr[visit - 1].type = "";
		tr[visit - 1].fio = "";
	} while (true);
}

void write()
{
	ofstream fout;
	fout.open("FILE.txt");

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			fout << i + 1 << " Гость" << '\n' << tr[i].passport << '\n' << tr[i].date_in << '\n' << tr[i].date_ot << '\n' << tr[i].type << '\n' << tr[i].fio << "\n\n";
		}
		fout.close();
		cout << "Данные записанны!\n";
	}
}