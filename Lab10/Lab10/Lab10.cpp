#include <iostream>
using namespace std;

int FUN(int n, int m) 
{
	if ((n + m) % 2 == 0)
	{
		if (n > m) return n;
		else return m;
	}
	else
	{
		return FUN((n + m + 1) / 2, n + 1) + FUN(m, (n + m + 1) / 2);
	}
}

int numsq(int a, int b) 
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
	int n, m;
	cout << "Введите n:";
	cin >> n;
	cout << "Введите m:";
	cin >> m;
	cout << FUN(n, m) << endl;

	system("pause");

	int a, b;
	cout << "Введите a:";
	cin >> a;
	cout << "Введите b:";
	cin >> b;
	cout << numsq(a, b);
}
