#include <iostream>
using namespace std;

double pownum(int p, double num)//функция возведения в положительнуб целую степень
{
    double res = 1;
    for (int i = 0; i < p; i++)
    {
        res *= num;
    }
    return res;
}

int main()
{
    cout << " enter n\n ";
    int n;
    cin >> n;
    cout << " enter x\n ";
    double x;
    cin >> x;
    double a;
    double res = 0;
    for (int i = 0; i < n + 1; i++)
    {
        cout << " enter a" << i << endl; 
        cin >> a; //записываем в переменную а значение а0, потом а1, а2 и тд...
        res += a * pownum(i, x); // сразу считаем результат
    }

    cout << endl << res;

}

