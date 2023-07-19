#include <iostream>
#include "struct.h"
using namespace std;

void addQueue(ochered* Finish)
{
	ochered* This = Finish;
	unsigned short size;
	cout << "Введите размер очереди: ";
	cin >> size;
	for (short i = 0; i < size; i++)
	{
		Finish = new ochered;
		This->next = Finish;
		cin >> This->numb;
		This = Finish;
	}
	This->next = nullptr;
}

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

void delQueue(ochered* Start)
{
	unsigned short el;
	ochered* This;
	This = Start;
	cout << "Какой элемент вы хотите удалить: ";
	cin >> el;
	for (short i = 1; true; i++)
	{
		if (i == el - 1)
		{
			ochered* DEL = This->next;
			This->next = This->next->next;
			el = DEL->numb;
			delete DEL;
			break;
		}
		This = This->next;
	}
	cout <<"Элемент удалён: "<< el << endl;
}

void maxmin(ochered* Start)
{
	ochered* This;
	This = Start;
	int max = This->numb;
	while (This->next != nullptr)
	{
		if (max < This->numb) max = This->numb;
		This = This->next;
	}

	This = Start;
	int min = This->numb;
	while (This->next != nullptr)
	{
		if (min > This->numb) min = This->numb;
		This = This->next;
	}

	cout << "Минимальный элемент: " << min << endl;
	cout << "Максимальный элемент: " << max << endl;
	

	This = Start;
	unsigned int k = 0;
	while (This->next != nullptr)
	{
		if (This->numb == max || This->numb == min)
		{
			This = This->next;
			while (This->numb != max && This->numb != min)
			{
				k++;
				This = This->next;
			}
			break;
		}
		This = This->next;
	}
	cout << "Количество элементов: " << k << endl;
}