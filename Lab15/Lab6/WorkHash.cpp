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
	cout << "������� ��� ��������: ";
	cin >> numb;
	short key = Hash_Fun(numb);
	HashTab* This = (Tab + Hash_Fun(key));
	while (true)
	{
		if (key != Hash_Fun(This->year))
		{
			This->year = numb;
			cout << "������� ���:";
			cin >> This->NAME;
			cout << "������� ������: ";
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
				cout << "��� ��������: " << This->year << endl;
				cout << "���: " << This->NAME << endl;
				cout << "������: " << This->ADRESS << endl;
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
	cout << "������� ��� �������� ��. �������, ������ ������� �� ������ �����������: ";
	cin >> numb;
	short key = Hash_Fun(numb);

	nowTime = clock();
	HashTab* This = (Tab + key);

	while (true)
	{
		if (!This->year) {
			cout << "����� ����������� �������� ���!" << endl;
			break;
		}
		else
		{
			cout << "��� ��������: " << This->year << endl;
			cout << "���: " << This->NAME << endl;
			cout << "������: " << This->ADRESS << endl;
			cout << "------------------------------------------------------------------------------------------------------------" << endl;
			if (This->colision) This = This->colision;
			else break;
		}
	}
	deltaTime = clock();
	Time = ((double)deltaTime - (double)nowTime) / (double)CLOCKS_PER_SEC;
	cout << "����� ������: " << Time << endl;
}

void del(HashTab* Tab)
{
	short numb;
	cout << "������� ��� �������� ��. �������, ������ ������� �� ������ �������: ";
	cin >> numb;
	int key = Hash_Fun(numb);
	if (!Tab[key].year) {
		cout << "����� ����������� �������� ���!" << endl;
	}
	else
	{
		HashTab* This = (Tab + key);
		delALL(This, Tab + key);
	}
}