#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>
#include <ctime>


#define DEBUG


using namespace std;


struct processor
{
    string cpu;
    int freaq;
    char type;
};


void output(processor a[], int n);
void msort(processor a[], int n, int k);


void menu(processor a[], int n)
{
#ifdef DEBUG
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата: "<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: menu.cpp; текущая функция: menu " << endl;
#endif

    int u;
    cout << "\n выберите действие:\n";
    cout << " 1 - сортировка;\n";
    cout << " 2 - вывод данных массива структур;\n";
    cout << " 0 - выход из программы.\n";

    cin >> u;

    switch(u)
    {

    case 1:
    {
        cout << "\n";
        cout << " 1 - сортировать по фамилиям студентов;\n";
        cout << " 2 - сортировать по возрасту студентов;\n";
        cout << " 3 - сортировать по среднему баллу студентов.\n";

        cin >> u;
        msort(a, n, u);
        menu(a, n);
        break;
    }
    case 2:
    {
        output(a, n);
        menu(a, n);
        break;
    }

    case 0:
    {
#if defined DEBUG
        seconds = time(NULL);
        timeinfo = localtime(&seconds);
        cout<<"Текущее время и дата: "<<asctime(timeinfo)<<endl;
        cin.get();
#else
        cout << "Текущий файл: menu.cpp; текущая функция: menu " << endl;
#endif
        break;
    }
    }

}
