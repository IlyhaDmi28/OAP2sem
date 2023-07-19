#include "Hash.h"
#include <time.h>

int Hash_Fun(short key)
{
	double A = 0.6;
	if (key % 2 == 0) return key % SIZE;
	else return SIZE * fmod(key * A, 1);
}

void delALL(HashTab* This, HashTab* Tab)
{
	if (This->colision) delALL(This->colision, Tab);
	if (This = Tab) This->year = 0;
	else delete This;
}

void add(HashTab *Tab)
{
	short numb;
	cout << "Введите год создания: ";
	cin >> numb;
	short key = Hash_Fun(numb);
	HashTab* This = (Tab + Hash_Fun(key));
	while (true)
	{
		if (key != Hash_Fun(This->year))
		{
			This->year = numb;
			cout << "Введите имя:";
			cin >> This->NAME;
			cout << "Введите адресс: ";
			cin >> This->ADRESS;
			break;
		}
		else
		{
			if (!This->colision) This->colision = new HashTab;
			This = This->colision;
		}
	}
}

void out(HashTab* Tab)
{
	HashTab* This;
	for (int i = 0; i < SIZE; i++)
	{
		This = Tab + i;
		if (This->year)
		{
			while (true)
			{
				cout << "Год создания: " << This->year << endl;
				cout << "Имя: " << This->NAME << endl;
				cout << "Адресс: " << This->ADRESS << endl;
				cout << "------------------------------------------------------------------------------------------------------------" << endl;
				if (This->colision) This = This->colision;
				else break;
			}
		}
	}
}

void find(HashTab* Tab)
{
	clock_t nowTime, deltaTime;
	double Time;

	short numb;
	cout << "Введите год создания эл. адресса, данные которых вы хотите просмтореть: ";
	cin >> numb;
	short key = Hash_Fun(numb);

	nowTime = clock();
	HashTab* This = (Tab + key);

	while (true)
	{
		if (!This->year) {
			cout << "Таких электронных адрессов нет!" << endl;
			break;
		}
		else
		{
			cout << "Год создания: " << This->year << endl;
			cout << "Имя: " << This->NAME << endl;
			cout << "Адресс: " << This->ADRESS << endl;
			cout << "------------------------------------------------------------------------------------------------------------" << endl;
			if (This->colision) This = This->colision;
			else break;
		}
	}
	deltaTime = clock();
	Time = ((double)deltaTime - (double)nowTime) / (double)CLOCKS_PER_SEC;
	cout << "Время поиска: " << Time << endl;
}

void del(HashTab* Tab)
{
	short numb;
	cout << "Введите год создания эл. адресса, данные которых вы хотите удалить: ";
	cin >> numb;
	int key = Hash_Fun(numb);
	if (!Tab[key].year) {
		cout << "Таких электронных адрессов нет!" << endl;
	}
	else
	{
		HashTab* This = (Tab + key);
		delALL(This, Tab + key);
	}
}