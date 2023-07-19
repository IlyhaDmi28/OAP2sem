//Сортировка пузырьком, сортировка выбором, сортировка подсчетом
#include <iostream>
#include <chrono>
#include <time.h>
#include <ctime>
using namespace std;
int i, j, key = 0, temp = 0, d;
int first, last;
clock_t time_c1, time_c2, time_1;

void coppyArray(int* A, int* B, int* C, int* D, int* E, int SIZE);
void puzar(int* B, int SIZE);
//void sortInset(int* C, int SIZE);
void sortChoice(int* D, int SIZE);
void sortQuick(int* E, int SIZE, int* D);



//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	int SIZE;
	cout << "Количество элементов в массиве = "; cin >> SIZE;
	int* A = new int[SIZE];
	int* B = new int[SIZE];
	int* C = new int[SIZE];
	int* D = new int[SIZE];
	int* E = new int[SIZE];
	for (i = 0; i < SIZE; i++) //ввод массива
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	//B[i] = A[i];
	//C[i] = A[i];
	//D[i] = A[i];
	//E[i] = A[i];
	coppyArray(A, B, C, D, E, SIZE);
	puzar(B, SIZE);
	//sortInset(C, SIZE);
	sortChoice(D, SIZE);
	sortQuick(E, SIZE, D);
}

void coppyArray(int* A, int* B, int* C, int* D, int* E, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}
}

void puzar(int* B, int SIZE) //cортировка пузырьком
{
	auto begin_d = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1 - i; j++) {
			if (B[j] > B[j + 1]) {
				int b = B[j]; // создали дополнительную переменную
				B[j] = B[j + 1]; // меняем местами
				B[j + 1] = b; // значения элементов
			}
		}
	}
	auto end_d = std::chrono::high_resolution_clock::now();
	auto time_took_d = std::chrono::duration_cast<std::chrono::duration<double>>(end_d - begin_d);
	cout << endl << "Результирующий массив(сортировка пузырьком): ";
	for (i = 0; i < SIZE; i++)
		cout << B[i] << " ";
	cout << endl << "Время: " << time_took_d.count();

}



void sortChoice(int* D, int SIZE) //сортировка выбора
{
	auto begin_d = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE - 1; i++) {
		/* устанавливаем начальное значение минимального индекса */
		int min_i = i;
		/* находим индекс минимального элемента */
		for (int j = i + 1; j < SIZE; j++) {
			if (D[j] < D[min_i]) {
				min_i = j;
			}
		}
		/* меняем значения местами */
		int temp = D[i];
		D[i] = D[min_i];
		D[min_i] = temp;
	}
	auto end_d = std::chrono::high_resolution_clock::now();
	auto time_took_d = std::chrono::duration_cast<std::chrono::duration<double>>(end_d - begin_d);
	cout << endl << "Результирующий массив(сортировка выбора): ";
	for (i = 0; i < SIZE; i++)
		cout << D[i] << " ";
	cout << endl << "Время: " << time_took_d.count();
}

void sortQuick(int* E, int SIZE, int* D) //сортировка подсчётом
{
	auto begin_d = std::chrono::high_resolution_clock::now();

	int i, j, count;
	for (i = 0; i < SIZE; ++i)
	{
		for (count = 0, j = 0; j < SIZE; ++j)
			if (E[j] < E[i] || (E[j] == E[i] && i < j))
				count++;
		E[count] = E[i];
	}

	auto end_d = std::chrono::high_resolution_clock::now();
	auto time_took_d = std::chrono::duration_cast<std::chrono::duration<double>>(end_d - begin_d);
	cout << endl << "Результирующий массив(сортировка подсчётом): ";
	for (i = 0; i < SIZE; i++)
		cout << D[i] << " ";
	cout << endl << "Время: " << time_took_d.count();

}