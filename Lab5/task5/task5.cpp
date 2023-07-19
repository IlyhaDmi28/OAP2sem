#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;

union voksal
{
	unsigned short number;
	char way[20];
	char day[20];
	unsigned short timePrib;
	unsigned short timeOt;
} tr[4];

struct voks
{
public:
	unsigned short number;
	string way;
	string day;
	unsigned short timePrib;
	unsigned short timeOt;
} train[4];

void input();
void output();
void finput();
void foutput();
void find();

void main()
{
	unsigned short choise;
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	do
	{
		cout << "1. Ввод данных" << endl;
		cout << "2. Запись в файл" << endl;
		cout << "3. Вывод данных" << endl;
		cout << "4. Просмотр файла" << endl;
		cout << "5. Поиск по пункту назначения" << endl;
		cout << "0. ВЫХОД!" << endl;
		cout << "\nВыберите пункт" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1: { input(); cout << endl; break; }
		case 2: { foutput(); cout << endl; break; }
		case 3: { output(); cout << endl; break; }
		case 4: { finput(); cout << endl; break; }
		case 5: { find(); cout << endl; break; }
		}
	} while (choise != 0);
}

void input()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "Введите номер поезда: ";
		cin >> tr[i].number;
		train[i].number = tr[i].number;
		cout << "Введите пункт назначения: ";
		cin >> tr[i].way;
		train[i].way = tr[i].way;
		cout << "Введите день следования: ";
		cin >> tr[i].day;
		train[i].day = tr[i].day;
		cout << "Введите время отправления: ";
		cin >> tr[i].timeOt;
		train[i].timeOt = tr[i].timeOt;
		cout << "Введите время прибытия: ";
		cin >> tr[i].timePrib;
		train[i].timePrib = tr[i].timePrib;
		cout << '\n';
	}
}

void output()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "Номер поезда: " << train[i].number << endl;
		cout << "Пункт назначения: " << train[i].way << endl;
		cout << "День следования: " << train[i].day << endl;
		cout << "Время отправления: " << train[i].timeOt << endl;
		cout << "Время прибытия: " << train[i].timePrib << endl;
		cout << '\n';
	}
}

void finput()
{
	string str;
	ifstream fin;
	fin.open("FILE.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	else
	{
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << '\n';
		}
	}
	fin.close();
}

void find()
{
	string way;
	cout << "Введите пункт назначения, куда отправляется ваш поезд: ";
	cin >> way;
	for (int i = 0; i < 4; i++)
	{
		if (train[i].way == way)
		{
			cout << "Номер поезда: " << train[i].number << endl;
			cout << "Пункт назначения: " << train[i].way << endl;
			cout << "День следования: " << train[i].day << endl;
			cout << "Время отправления: " << train[i].timeOt << endl;
			cout << "Время прибытия: " << train[i].timePrib << endl;
			cout << '\n';
		}
	}
}

void foutput()
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
			fout << "Номер поезда: " << train[i].number << endl << "Пункт назначения: " << train[i].way << endl << "День следования: " << train[i].day << endl << "Время отправления: " << train[i].timeOt << endl << "Время прибытия: " << train[i].timePrib << "\n\n";
		}
	}
		fout.close();
		cout << "Данные записанны!\n";
}