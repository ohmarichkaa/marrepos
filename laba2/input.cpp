#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>
#include <ctime>

//#define DEBUG

using namespace std;

struct processor
{
    string cpu;
    int freaq;
    char type;
};




void input(processor a[], int n)
{
#if defined DEBUG
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: input.cpp; текущая функция: input " << endl;
#endif

    for (int i = 0; i < n; i++)
    {
        cout << "\nВведите фамилию студента: ";
        cin >> a[i].cpu;
        cout << "\nВведите возраст студента: ";
        cin >> a[i].freaq;
        cout << "\nВведите среднийй балл студента: ";
        cin>> a[i].type;
    }
#if defined DEBUG
    seconds = time(NULL);
    timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: input.cpp; текущая функция: input " << endl;
#endif
}


void random(processor a[], int n)
{
#if defined DEBUG
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: input.cpp; текущая функция: random " << endl;
#endif
    static const char alphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static const char t[] =
        "CR";
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i].cpu = alphabet[rand() % 26];
        int cnt = rand() % 5 + 5;
        for (int u = 0; u < cnt; u++)
        {
            a[i].cpu += alphabet[rand() % 26 + 26];
        }
        a[i].freaq = rand() % 3000 + 1000;

        a[i].type = t[rand() % 2];
    }
#if defined DEBUG
    seconds = time(NULL);
    timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: input.cpp; текущая функция: random " << endl;
#endif
}

