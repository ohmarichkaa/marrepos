#include <iostream>
using namespace std;


void solution(int a, int b, int *gcf, int *lcm) //наибольший общий делитель
{
	int f2 = 1;
	int f1 = a % b; //остаток от деления большего исходного числа на меньшее
	if (f1 == 0)
	{		
		*gcf = b;
	} //если равен нулю, функция прекращает свою работу, выводит меньшее из исходных
	if (*gcf == 0)
	{
		f2 = b % f1; //остаток от деления меньшего числа на первый остаток
		if (f2 == 0)
		{
			*gcf = f1;
		} //если равен нулю, функция выводит результат и прекращает свою работу
	}
	if (*gcf == 0)
	{
	int tmp;//временная переменная, чтобы не терять данные
	while (f2 != 0 && f1 % f2 != 0)//пока остаток от деления предыдущего остатка на текущий не равен нулю
	{
		tmp = f2; //запоминаем последний остаток
		f2 = f1 % f2; //считаем следующий остаток
		f1 = tmp; //переписываем больший остаток
	};	
		*gcf = f2;	
	}

	*lcm = abs(a * b) / *gcf; //по формуле: модуль произведения двух чисел, деленный на их наибольший общий делитель
}



int main()
{
	int n;
	int m;
	int gcf = 0;
	int lcm = 0;
	cout << " enter num 1\n ";
	cin >> n;
	cout << " enter num 2\n ";
	cin >> m;
	cout << " greatest common factor\n ";
	if (m > n)
		solution(m, n, &gcf, &lcm);
	else
		solution(n, m, &gcf, &lcm);
	cout << gcf;
	cout << "\n least common multiple\n ";

	cout << lcm;
}
