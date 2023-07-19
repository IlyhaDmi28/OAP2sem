#include <iostream>
#include "stutic.h"
using namespace std;

void main()
{
    setlocale(LC_CTYPE, "RUS");
    ochered* Start, * Finish = nullptr;
    Finish = new ochered;
    Start = Finish;
    do
    {
        unsigned short ch;
        cout << "1.Ввод данных\n";
        cout << "2.Вывод данных\n";
        cout << "3.Удаление данных\n";
        cout << "0.Выход\n\n";

        cout << "Выберите пункт: ";
        cin >> ch;
        switch (ch) {
        case 1: {
                ochered* This = Finish;
                unsigned short size;
                cout << "Cколько элементов вы хотите ввести: ";
                cin >> size;
                for (short i = 0; i < size; i++)
                {
                    Finish = new ochered;
                    This->next = Finish;
                    Finish->pre = This;
                    cin >> This->numb;
                    This = Finish;
                }
                This->next = nullptr;
                Finish = This->pre;
                break; 
                }
        case 2: outQueue(Start); break;
        case 3: deleteKFirst(Finish); break;
        case 0: return;
        default: cout << "\nНет такого пункта. Повторите ввод!" << endl; break;
        }
    } while (true);
}