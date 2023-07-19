#include <iostream>
#include "struct.h"
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
        cout << "4.Поиск количество элементов между макс и мин элементами очереди\n";
        cout << "0.Выход\n\n";

        cout << "Выберите пункт: ";
        cin >> ch;
        switch (ch) {
            case 1: addQueue(Finish); break;
            case 2: outQueue(Start); break;
            case 3: delQueue(Start); break;
            case 4: maxmin(Start); break;
            case 0: return;
            default: cout << "\nНет такого пункта. Повторите ввод!" << endl; break;
        }
    } while (true);
}