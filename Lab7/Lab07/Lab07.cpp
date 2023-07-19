#include "stdafx.h"
#include <iostream>
#include "myStack.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; 
	myStk->head = NULL;       
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Запись в файл" << endl;
		cout << "5 - Просмотр файла" << endl;
		cout << "6 - Очистка стека" << endl;
		cout << "0 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: pop(myStk);
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: fOut(myStk);
			break;
		case 5: fInp();
			break;
		case 6: cle(myStk);
			break;
		case 0: return 0;
			break;
		}
	}
	return 0;
}
