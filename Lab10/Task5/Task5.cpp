#include <iostream>
using namespace std;

int numsq(int a, int b) //12 6 
{
	if (b == 0) return 0;
	else
	{
		return floor(a / b) + numsq(b, a % b);
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int a, b;
	cout << "Введите a:";
	cin >> a;
	cout << "Введите b:";
	cin >> b;
	cout << numsq(a, b);
}
