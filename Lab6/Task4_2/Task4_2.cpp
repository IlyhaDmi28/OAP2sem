#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct numbers
{
	int num;
    numbers* PointerPre;
};

int addNum(int el, numbers* This);
int delNum(int el);
void find(int el);
void out(int el);
void writeF(int el);
void readF();

void main()
{
    setlocale(LC_ALL, "RUS");
	numbers * Last, * Pre = nullptr;
	int midArf = 0, el = 0;
	unsigned short choise;
	do
	{
		cout << "1. Добавить элементы" << endl;
		cout << "2. Удалить элементы" << endl;
		cout << "3. Поиск элемента" << endl;
		cout << "4. Вывод списка" << endl;
		cout << "5. Записать данные в файл" << endl;
		cout << "6. Прочесть данные в файле" << endl;
		cout << "\nВыберите действие(0 - выход): ";
		cin >> choise;
		switch (choise)
		{
			case 1: 
			{
				numbers* This;
				while (true)
				{
					cout << "Введите число: ";
					This = new numbers;
					cin >> This->num;
					if (!This->num) { delete This; break; }
					This->PointerPre = Pre;
					Pre = This;
					el++;
				}
				break;
			}
			case 2:
			{
				numbers* This; 
				This = Pre;
				cout << "Выберите номер элемента, который вы хотите удалить: ";
				int i;
				cin >> i;
				for (int n = 0; n < i; n++)
				{ 
					if (n + 1 == i)
					{
						This->num = 0;
						break;
					}
					This = This->PointerPre;
				}
				break;
			}
			case 3: 
			{
				numbers* This = Pre;
				int numb;
				cout << "Введите число, которое вы хотите найти: ";
				cin >> numb;
				for (int n = 0; n < el; n++)
				{
					if (This->num == numb) cout << numb << ' ';
					This = This->PointerPre;
				}
				break;
				cout << endl;
			}
			case 4:
			{

				int midArf = 0, i = 0;
				numbers* This = Pre;

				while (This)
				{
					if(This->num) cout << This->num << ' ';
					This = This->PointerPre;
				}

				This = Pre;
				while (This)
				{
					if (This->num > 0) { midArf += This->num; i++; }
					This = This->PointerPre;
				}

				midArf = midArf / i;
				cout << "\nСреднее арифмитическое положительных элемнтов: " << midArf << endl;
				break;
			}
			case 5:
			{
				numbers* This = Pre;
				ofstream fout;
				fout.open("FILE.txt");

				if (!fout.is_open())
				{
					cout << "Ошибка открытия файла" << endl;
					return;
				}
				else
				{
					while (This)
					{
						fout << This->num << ' ';
						This = This->PointerPre;
					}
					
				}
				fout.close();
				cout << "Данные записанны!\n";
				break;
			}
			case 6:
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
				break;
			}
		};
	} while (choise);
}

//int addNum(int el)
//{
//	while (true)
//	{
//		cout << "Введите число: ";
//		This = new numbers;
//		cin >> This->num;
//		if (!This->num) { delete This; break; }
//		This->PointerPre = Pre;
//		el++;
//	}
//
//	/*while (Pre)
//	{
//		This = Pre;
//		Pre = Pre->PointerPre;
//		delete This;
//	}*/
//	return el;
//}
//
//int delNum(int el)
//{
//	numbers* This;
//	cout << "Выберите номер элемента, который вы хотите удалить: ";
//	int i, n = 0;
//	cin >> i;
//	while (n < el)
//	{
//		This = new numbers;
//		if (n == i)
//		{
//			while (n < el)
//			{
//				This = new numbers;
//				This->PointerPre->num = This->num;
//				if (n == el - 1)
//				{
//					el--;
//					delete This;
//				}
//			}
//			break;
//		}
//		n++;
//	}
//	return el;
//}
//
//void find(int el)
//{
//	int numb;
//	numbers* This;
//	cout << "Введите число, которое вы хотите найти: ";
//	cin >> numb;
//	for (int n = 0; n < el; n++)
//	{
//		This = new numbers;
//		if (This->num == numb) cout << numb << ' ';
//	}
//}
//
//void writeF(int el)
//{
//	numbers* This;
//	ofstream fout;
//	fout.open("FILE.txt");
//
//	if (!fout.is_open())
//	{
//		cout << "Ошибка открытия файла" << endl;
//		return;
//	}
//	else
//	{
//		for (int n = 0; n < el; n++)
//		{
//			This = new numbers;
//			fout << This->num << ' ';
//		}
//	}
//	fout.close();
//	cout << "Данные записанны!\n";
//}
//
//void readF()
//{
//	string str;
//	ifstream fin;
//	fin.open("FILE.txt");
//	if (!fin.is_open())
//	{
//		cout << "Ошибка открытия файла" << endl;
//		return;
//	}
//	else
//	{
//		while (!fin.eof())
//		{
//			str = "";
//			getline(fin, str);
//			cout << str << '\n';
//		}
//	}
//	fin.close();
//}
//
//void out(int el)
//{
//	int midArf = 0, i = 0;
//	numbers* This, * Pre = nullptr;
//	for (int n = 0; n < el; n++)
//	{
//		This = new numbers;
//	}
//	This = This->PointerPre;
//	
//	while (This)
//	{
//		cout << This->num << ' ';
//		This = This->PointerPre;
//	}
//
//	This = Pre;
//	while (This)
//	{
//		if (This->num > 0) { midArf += This->num; i++; }
//		This = This->PointerPre;
//	}
//
//	midArf = midArf / i;
//	cout << "\nСреднее арифмитическое положительных элемнтов: " << midArf;
//}
