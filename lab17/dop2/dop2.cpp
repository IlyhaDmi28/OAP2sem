﻿//Дан массив целых чисел, количество элементов которого надо ввести с клавиатуры. Найти максимальный элемент массива и его номер, при условии, что все элементы различны. Найти минимальный элемент массива.
#include <iostream>
#include <ctime>
using namespace std;

void choicesSort(int* arrayPtr, int length_array) // сортировка выбором
{
    
    for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
    {
        int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
        {
            if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
            {
                temp = arrayPtr[repeat_counter];
                arrayPtr[repeat_counter] = arrayPtr[element_counter];
                arrayPtr[element_counter] = temp;
                

            }
        }
    }

}



void randomize(int* arr, int n)
{
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
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
    choicesSort(arrA, n);
    cout << endl << "Макисмальный элемент массива = " << arrA[n - 1]<< endl;
    cout << "Минимальный элемень = " << arrA[0];



}