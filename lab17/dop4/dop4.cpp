// Дан массив из 15 целых чисел на отрезке [-5; 5]. Упорядочить массив, удалив повторяющиеся элементы.
#include <iostream>
#include <ctime>
using namespace std;

int del(int* arr, int n)
{
    int buf;
    for (int i = 0; i < n; i++)
    {
        buf = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == buf)
            {
                n = n - 1;
                for (int a = j; a < n; a++)
                    arr[a] = arr[a + 1];

            }

        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j]; // создали дополнительную переменную
                arr[j] = arr[j + 1]; // меняем местами
                arr[j + 1] = b; // значения элементов
            }
        }
    }

    cout << endl << "Результирующий массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return n;
}

void puzar(int* arr, int n) //cортировка пузырьком
{

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j]; // создали дополнительную переменную
                arr[j] = arr[j + 1]; // меняем местами
                arr[j + 1] = b; // значения элементов
            }
        }
    }

    cout << endl << "Результирующий массив(сортировка пузырьком): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void randomize(int* arr, int n)
{
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = -5 + rand() % ((5 + 1) - -5);
        cout << arr[i] << " ";

    }
}

void print(int* arr, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";

    }
}
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер массива А :";
    cin >> n;
    int* arrA = new int[n];

    randomize(arrA, n);
    n = del(arrA, n);
    //n = del(arrA, n);
    //print(arrA, n);
    //puzar(arrA, n);




}