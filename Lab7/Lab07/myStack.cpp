#include "stdafx.h"
#include <iostream>
#include "myStack.h"
#include <fstream>
#include <string>
using namespace std;

void push(int x, Stack* myStk)  
{
	Stack* e = new Stack;    
	e->data = x;           
	e->next = myStk->head;   
	myStk->head = e;         
}
void pop(Stack* myStk)  
{
	if (myStk->head == nullptr)
	{
		cout << "Стек пуст!" << endl;           
	}
	else
	{
		Stack* This = myStk->head;
		Stack* ThisNow;
		while (This != NULL)
		{
			/*Stack* This = myStk->head;*/   //е - переменная для хранения адреса элемента
			int a = This->data; 
			ThisNow = This;//запись числа из поля data в переменную a 

			This = This->next; //перенос вершины
			if (a < 0)
			{
				//Stack* ThisNowNow = myStk->head;
				while (This != NULL)
				{
					ThisNow->data = This->data;
					ThisNow->next = This->next;
					ThisNow->head = myStk->head;
					This = This->next;
				}
				break;
			}
		}
	}
	cout << "Отрицательный элемент извлечён\n";
}
void show(Stack* myStk)    
{
	Stack* e = myStk->head;   
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void fOut(Stack* myStk)  
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
		Stack* e = myStk->head;  
		int a;
		if (e == NULL)
			cout << "Стек пуст!" << endl;
		while (e != NULL)
		{
			a = e->data;       
			fout << a << " ";
			e = e->next;
		}
		cout << endl;

	}
	fout.close();
	cout << "Данные записанны!\n";
}

void fInp()
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

void cle(Stack* myStk)   
{
	Stack* This = myStk->head;   
	Stack* Pre = This;
	while (Pre != NULL)
	{
		This = This->next;
		delete Pre;
		Pre = This;
	}
	myStk->head = NULL;
}

