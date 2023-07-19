#include <iostream>
#include "stutic.h"
using namespace std;

void outQueue(ochered* Start)
{
	ochered* This;
	This = Start;
	while (This->next != nullptr)
	{
		cout << This->numb << ' ';
		This = This->next;
	}
	cout << endl;
}

void deleteKFirst(ochered* Finish)
{
	ochered* This;
	This = Finish;
	unsigned int k;
	cout << "Сколько элементов вы хотите удалить: ";
	cin >> k;
	for (short i = 0; i < k - 1; i++)
	{
		Finish = Finish->pre;
		delete This;
		This = Finish;
	}
	This->next = nullptr;
	cout << "Данные удаленны!" << endl;
}