#include <iostream>
using namespace std;

int main()
{
    double array[10][10];
    int n;
    cout << "enter size:    ";
    cin >> n;
    double d1 = 0, d2 = 0; //ввеличины главной и побочной диагонали
    cout << "\nenter array: \n";
    for (int i = 0; i < n; i++) // строки
    {
        for (int j = 0; j < n; j++) // столбцы
        {            
            cin >> array[i][j]; 

            if (j == n - 1 - i) //если сейчас работаем с элементом который находится на побочной диагонали
            {
                d2 += array[i][j]; //то добавляем его в сумму элементов побочной диагонали
            }
        }
        d1 += array[i][i]; //считаем сумму элементов главной диагонали
    }
    cout << "\nresult:    ";
    if (d1 > d2) //если сумма элементов главной диагонали больше чем суммв элементов побочной
        cout << 1; // выводим один
    else if (d1 == d2) // если они равны
        cout << "diagonals are equal";
    else //если суммы не равны и главная диагональ меньше побочной
        cout << -1; // выводим минус один

    cout << endl;
}
