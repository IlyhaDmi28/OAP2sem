#include "Hash.h"
#include <time.h>

int Hash_Fun(short key)
{
	double A = 0.6;
	if (key % 2 == 0) return key % SIZE;
	else return SIZE * fmod(key * A, 1);
}

void add(HashTab *Tab)
{
	short numb;
	cout << "Введите ключ: ";
	cin >> numb;
	short key = Hash_Fun(numb);
	HashTab* This = (Tab + Hash_Fun(key));
	while (true)
	{
		if (key != Hash_Fun(This->year) && !This->year)
		{
			This->year = key;
			cout << "Введите слово:";
			cin >> This->NAME;
			break;
		}
		else
		{
			This = This + 1;
		}
	}
}

void out(HashTab* Tab)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (Tab[i].year) cout << Tab[i].NAME << endl;
	}
}

void find(HashTab* Tab)
{
	short numb;
	cout << "Введите ключ: ";
	cin >> numb;
	short key = Hash_Fun(numb);
	bool findYES = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (Tab[i].year == key) { cout << Tab[i].NAME << endl; findYES = true; }
	}
	if (!findYES) cout << "Ничего не найденно!";
}

void del(HashTab* Tab)
{
	short numb;
	cout << "Введите ключ: ";
	cin >> numb;
	short key = Hash_Fun(numb);
	bool findYES = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (Tab[i].year == key) { Tab[i].year = 0; findYES = true; }
	}
	if (!findYES) cout << "Ничего не найденно!";
}