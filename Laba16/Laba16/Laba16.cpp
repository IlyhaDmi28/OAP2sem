#include "Sort.h"

void main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Введите размер массива: ";
    int SIZE;
    cin >> SIZE;
    int *A = new int[SIZE];
    int *B = new int[SIZE];
    int *C = new int[SIZE];
    cout << "Массив A: ";
    for (int i = 0; i < SIZE; i++)
    {
        A[i] = rand() % 100;
        B[i] = rand() % 100;   
        cout << A[i] << ' ';
    }
    cout << "\nМассив B: ";
    for (int i = 0; i < SIZE; i++)
    {
        if (!(i % 2) && (A[i + 1] % 2)) B[i] = A[i];
        cout << B[i] << ' ';
        C[i] = B[i];
    }
    cout << "\nСортировка выбором: ";
    select(B, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << B[i] << ' ';
    }
    cout << "\nСортировка Хоара: ";
    qsortRecursive(C, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << C[i] << ' ';
    }
}

