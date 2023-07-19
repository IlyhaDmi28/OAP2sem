#include<iostream> //Доп 2
#include<windows.h>
#include<fstream>
using namespace std;
#define size 8

void enter();
void out();
void del();
void time_check();
void sort();


struct train
{
	char punkt[15];
	int number;
	float time;
};
train a[size];
int oper, size_end = 0;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записи(ей)" << endl;

	cout << "4-для простомотра по времени" << endl;

	cout << "6-для выхода" << endl;
	cin >> oper;
	do
	{
		switch (oper)
		{
		case 1: enter(); break;
		case 2: out(); break;

		case 4: time_check(); break;
		}
	} while (oper != 6);
	system("pause");
}
void enter()
{
	if (size_end < size)
	{
		cout << "Введите пункт назначения: ";
		cin >> a[size_end].punkt;
		cout << "Введите номер поезда: ";
		cin >> a[size_end].number;
		cout << "Введите время отправления: ";
		cin >> a[size_end].time;
		a[size_end].time = round(a[size_end].time * 100) / 100;
		size_end++;
		cout << "-------------------------------------------" << endl;
	}
	cout << "следующее действие?" << endl;
	cin >> oper;
}
void out()
{
	sort();
	for (int i = 0; i < size_end; i++)
	{
		cout << "Пункт назначения: " << a[i].punkt << endl;
		cout << "Номер поезда: " << a[i].number << endl;
		cout << "Время отправления: " << a[i].time << endl;
		cout << "-------------------------------------------" << endl;
	}
	cout << "Cледующее действие?" << endl;
	cin >> oper;

}
void time_check()
{
	float z;
	cout << "Введите время до которого выводить расписание поездов: "; cin >> z;
	for (int i = 0; i < size_end; i++)
	{
		if (a[i].time < z)
		{
			cout << "Пункт назначения: " << a[i].punkt << endl;
			cout << "Номер поезда: " << a[i].number << endl;
			cout << "Время отправления: " << a[i].time << endl;
			cout << "-------------------------------------------" << endl;
		}
	}
}
void sort()
{
	char buf[15];
	int buf2;
	float buf3;
	if (size_end > 1)
	{
		for (int j = 0; j < size_end; j++) {
			for (int k = 0; k < size_end + 1; k++)
			{
				if ((int)a[k].punkt[0] > (int)a[k + 1].punkt[0])
				{
					for (int i = 0; i < 15; i++)
					{
						buf[i] = a[k].punkt[i];
					}
					for (int i = 0; i < 15; i++)
					{
						a[k].punkt[i] = a[k + 1].punkt[i];
					}
					for (int i = 0; i < 15; i++)
					{
						a[k + 1].punkt[i] = buf[i];
					}
					buf2 = a[k].number;
					a[k].number = a[k + 1].number;
					a[k + 1].number = buf2;
					buf3 = a[k].time;
					a[k].time = a[k + 1].time;
					a[k + 1].time = buf3;
				}
			}
		}
	}
}