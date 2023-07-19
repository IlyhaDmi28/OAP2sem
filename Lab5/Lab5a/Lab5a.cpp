#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct bytes
{
	unsigned a0 : 1;
	unsigned b0 : 1;
	unsigned c0 : 1;
	unsigned d0 : 1;
	unsigned e0 : 1;
	unsigned f0 : 1;
	unsigned g0 : 1;
	unsigned h0 : 1;
	unsigned a1 : 1;
	unsigned b1 : 1;
	unsigned c1 : 1;
	unsigned d1 : 1;
	unsigned e1 : 1;
	unsigned f1 : 1;
	unsigned g1 : 1;
	unsigned h1 : 1;
	unsigned a2 : 1;
	unsigned b2 : 1;
	unsigned c2 : 1;
	unsigned d2 : 1;
	unsigned e2 : 1;
	unsigned f2 : 1;
	unsigned g2 : 1;
	unsigned h2 : 1;
	unsigned a3 : 1;
	unsigned b3 : 1;
	unsigned c3 : 1;
	unsigned d3 : 1;
	unsigned e3 : 1;
	unsigned f3 : 1;
	unsigned g3 : 1;
	unsigned h3 : 1;
};

struct Citizen
{
	string fio;
	union bits
	{
		int date;
		bytes bit;
	} BirhtDay;
	bits b;
	char gender;
	unsigned short year;
};

enum gender
{
	woman = 'Ж', man = 'М'
};

Citizen civ[4];

void input();
void output();
void del();
void find();
short data(int date);

void main()
{
	unsigned short choise;
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	do
	{
		cout << "1. Ввод данных" << endl;
		cout << "2. Вывод данных" << endl;
		cout << "3. Удаление данных" << endl;
		cout << "4. Поиск гражданина по году рождения" << endl;
		cout << "\nВыберите пункт" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1: { input(); cout << endl; break; }
		case 2: { output(); cout << endl; break; }
		case 3: { del(); cout << endl; break; }
		case 4: { find(); cout << endl; break; }
		}
	} while (choise != 0);
}

void input()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "Введите Фамилию: ";
		cin >> civ[i].fio;
		cout << "Введите дату рождения: ";
		cin >> civ[i].BirhtDay.date;
		cout << "Укажите пол:\n1. женский\n2. мужской\n ";
		unsigned short choise;
		cin >> choise;
		switch (choise)
		{
		case 1: civ[i].gender = woman; break;
		case 2: civ[i].gender = man; break;
		}
	}
}

void output()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "ФИО: " << civ[i].fio << endl;
		cout << "Дата рождения: " << civ[i].BirhtDay.date << endl;
		cout << "Пол: " << civ[i].gender << endl;
		cout << "Дата рождения в битах: ";
		civ[i].b = civ[i].BirhtDay;
		if (civ[i].b.bit.h3) cout << "1";  else cout << "0";
		if (civ[i].b.bit.g3) cout << "1";  else cout << "0";
		if (civ[i].b.bit.f3) cout << "1";  else cout << "0";
		if (civ[i].b.bit.e3) cout << "1";  else cout << "0";
		if (civ[i].b.bit.d3) cout << "1";  else cout << "0";
		if (civ[i].b.bit.c3) cout << "1";  else cout << "0";
		if (civ[i].b.bit.b3) cout << "1";  else cout << "0";
		if (civ[i].b.bit.a3) cout << "1";  else cout << "0";
		if (civ[i].b.bit.h2) cout << "1";  else cout << "0";
		if (civ[i].b.bit.g2) cout << "1";  else cout << "0";
		if (civ[i].b.bit.f2) cout << "1";  else cout << "0";
		if (civ[i].b.bit.e2) cout << "1";  else cout << "0";
		if (civ[i].b.bit.d2) cout << "1";  else cout << "0";
		if (civ[i].b.bit.c2) cout << "1";  else cout << "0";
		if (civ[i].b.bit.b2) cout << "1";  else cout << "0";
		if (civ[i].b.bit.a2) cout << "1";  else cout << "0";
		if (civ[i].b.bit.h1) cout << "1";  else cout << "0";
		if (civ[i].b.bit.g1) cout << "1";  else cout << "0";
		if (civ[i].b.bit.f1) cout << "1";  else cout << "0";
		if (civ[i].b.bit.e1) cout << "1";  else cout << "0";
		if (civ[i].b.bit.d1) cout << "1";  else cout << "0";
		if (civ[i].b.bit.c1) cout << "1";  else cout << "0";
		if (civ[i].b.bit.b1) cout << "1";  else cout << "0";
		if (civ[i].b.bit.a1) cout << "1";  else cout << "0";
		if (civ[i].b.bit.h0) cout << "1";  else cout << "0";
		if (civ[i].b.bit.g0) cout << "1";  else cout << "0";
		if (civ[i].b.bit.f0) cout << "1";  else cout << "0";
		if (civ[i].b.bit.e0) cout << "1";  else cout << "0";
		if (civ[i].b.bit.d0) cout << "1";  else cout << "0";
		if (civ[i].b.bit.c0) cout << "1";  else cout << "0";
		if (civ[i].b.bit.b0) cout << "1";  else cout << "0";
		if (civ[i].b.bit.a0) cout << "1";  else cout << "0";
		cout << "\n\n";
	}
}

void del()
{
	unsigned short i;
	cout << "Данные какого горожанина вы хотите удалить(): ";
	cin >> i;
	civ[i - 1].fio = "";
	civ[i - 1].BirhtDay.date = NULL;
	civ[i - 1].gender = '\0';
	if (i - 1 <= 4) cout << "Данные усаешно удаленны!";
}

void find()
{
	unsigned short yearFind;
	cout << "Введите год рождения: ";
	cin >> yearFind;
	for (int i = 0; i < 2; i++)
	{
		if (yearFind == data(civ[i].BirhtDay.date))
		{
			cout << "ФИО: " << civ[i].fio << endl;
			cout << "Дата рождения: " << civ[i].BirhtDay.date << endl;
			cout << "Пол: " << civ[i].gender << endl;
			cout << "Дата рождения в битах: ";
			if (civ[i].b.bit.h3) cout << "1";  else cout << "0";
			if (civ[i].b.bit.g3) cout << "1";  else cout << "0";
			if (civ[i].b.bit.f3) cout << "1";  else cout << "0";
			if (civ[i].b.bit.e3) cout << "1";  else cout << "0";
			if (civ[i].b.bit.d3) cout << "1";  else cout << "0";
			if (civ[i].b.bit.c3) cout << "1";  else cout << "0";
			if (civ[i].b.bit.b3) cout << "1";  else cout << "0";
			if (civ[i].b.bit.a3) cout << "1";  else cout << "0";
			if (civ[i].b.bit.h2) cout << "1";  else cout << "0";
			if (civ[i].b.bit.g2) cout << "1";  else cout << "0";
			if (civ[i].b.bit.f2) cout << "1";  else cout << "0";
			if (civ[i].b.bit.e2) cout << "1";  else cout << "0";
			if (civ[i].b.bit.d2) cout << "1";  else cout << "0";
			if (civ[i].b.bit.c2) cout << "1";  else cout << "0";
			if (civ[i].b.bit.b2) cout << "1";  else cout << "0";
			if (civ[i].b.bit.a2) cout << "1";  else cout << "0";
			if (civ[i].b.bit.h1) cout << "1";  else cout << "0";
			if (civ[i].b.bit.g1) cout << "1";  else cout << "0";
			if (civ[i].b.bit.f1) cout << "1";  else cout << "0";
			if (civ[i].b.bit.e1) cout << "1";  else cout << "0";
			if (civ[i].b.bit.d1) cout << "1";  else cout << "0";
			if (civ[i].b.bit.c1) cout << "1";  else cout << "0";
			if (civ[i].b.bit.b1) cout << "1";  else cout << "0";
			if (civ[i].b.bit.a1) cout << "1";  else cout << "0";
			if (civ[i].b.bit.h0) cout << "1";  else cout << "0";
			if (civ[i].b.bit.g0) cout << "1";  else cout << "0";
			if (civ[i].b.bit.f0) cout << "1";  else cout << "0";
			if (civ[i].b.bit.e0) cout << "1";  else cout << "0";
			if (civ[i].b.bit.d0) cout << "1";  else cout << "0";
			if (civ[i].b.bit.c0) cout << "1";  else cout << "0";
			if (civ[i].b.bit.b0) cout << "1";  else cout << "0";
			if (civ[i].b.bit.a0) cout << "1";  else cout << "0";

			cout << "\n\n";
		}
	}
}

short data(int date)
{
	int day, month, year;
	day = date / 1000000;
	month = date / 10000;

	year = date - (10000 * month);
	month = month - (100 * day);
	return year;
}