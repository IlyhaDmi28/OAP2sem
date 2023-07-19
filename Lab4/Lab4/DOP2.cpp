//Определить структуру для представления информации о наличии санаторных путевок, содержащую следующие поля : 
//Название санатория, Место расположения, Лечебный профиль, Количество путевок.
//Представить введенные данные в виде таблицы, сгруппировав их по лечебным профилям санаториев.
//В пределах каждой группы данные отсортировать по названиям санаториев.Организовать поиск информации и вывод результатов.
#include<iostream>
#include<windows.h>
#include<fstream>
#include<iomanip>
using namespace std;
#define size 10

void enter();
void out();
void sort();
void search();


struct san
{
	char name[15];
	char locatiion[15];
	char prof[15];
	int putev;
};
san a[size];
int oper, size_end = 0;
int check = 0;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записи(ей)" << endl;
	cout << "4-для поиска по профилю" << endl;
	cout << "5-для выхода" << endl;
	cin >> oper;
	do
	{
		switch (oper)
		{
		case 1: enter(); break;
		case 2: out(); break;
		case 4: search(); break;
		}
	} while (oper != 5);
	system("pause");
}
void out()
{

	sort();
	string k1 = "Дыхательная", k2 = "Нервная", k3 = "Сердце";
	cout << "Название санатория" << "|" << "Место расположения" << "|" << "Лечебный профиль" << "|" << "Кол-во путевок" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size_end; i++)
	{
		if (a[i].prof == k1)
		{

			cout << setw(18) << a[i].name << "|" << setw(18) << a[i].locatiion << "|" << setw(16) << a[i].prof << "|" << setw(14) << a[i].putev << endl;
		}
	}
	for (int i = 0; i < size_end; i++)
	{
		if (a[i].prof == k2)
		{

			cout << setw(18) << a[i].name << "|" << setw(18) << a[i].locatiion << "|" << setw(16) << a[i].prof << "|" << setw(14) << a[i].putev << endl;
		}
	}
	for (int i = 0; i < size_end; i++)
	{
		if (a[i].prof == k3)
		{

			cout << setw(18) << a[i].name << "|" << setw(18) << a[i].locatiion << "|" << setw(16) << a[i].prof << "|" << setw(14) << a[i].putev << endl;
		}
	}
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void enter()
{
	if (size_end < size)
	{
		cout << "Введите название санатория: ";
		cin >> a[size_end].name;
		cout << "Введите месторасположения санатория: ";
		cin >> a[size_end].locatiion;
		cout << "Введите лечебнйы профиль (Нервная, Дыхательная, Оздоровление): ";
		cin >> a[size_end].prof;
		cout << "Введите количество путевок: ";
		cin >> a[size_end].putev;
		size_end++;
		cout << "-------------------------------------------" << endl;
	}
	if (size_end == size)
		cout << "Вы ввели максимальное кол-во записей" << endl;
	sort();
	cout << "следующее действие?" << endl;
	cin >> oper;
}
void sort()
{
	char buf[15];
	char buf2[15];
	char buf3[15];
	int buf4;
	if (size_end > 1)
	{
		for (int j = 0; j < size_end; j++) {
			for (int k = 0; k < size_end; k++)
			{
				if (a[k].name[0] > a[k + 1].name[0])
				{
					strcpy_s(buf, a[k].name);
					strcpy_s(a[k].name, a[k + 1].name);
					strcpy_s(a[k + 1].name, buf);

					strcpy_s(buf2, a[k].prof);
					strcpy_s(a[k].prof, a[k + 1].prof);
					strcpy_s(a[k + 1].prof, buf2);

					strcpy_s(buf3, a[k].locatiion);
					strcpy_s(a[k].locatiion, a[k + 1].locatiion);
					strcpy_s(a[k + 1].locatiion, buf3);
					buf4 = a[k].putev;
					a[k].putev = a[k + 1].putev;
					a[k + 1].putev = buf4;
				}
			}
		}
	}
}
void search()
{
	string scnd;
	cout << "Введите профиль санатория (Нервная, Дыхательная, Оздоровление): ";
	cin >> scnd;
	for (int i = 0; i < size_end; i++)
	{
		if (scnd == a[i].prof)
		{
			cout << "Название санатория: " << a[i].name << endl;
			cout << "Местоположение: " << a[i].locatiion << endl;
			cout << "Профиль: " << a[i].prof << endl;
			cout << "Кол-во путевок: " << a[i].putev << endl;
			cout << endl << "------------------------------------------ " << endl;

		}
	}
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}