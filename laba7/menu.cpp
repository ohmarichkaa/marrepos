#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>
#include <ctime>

using namespace std;


struct processor
{
    string cpu;
    int freaq;
    char type;
};


void foutput(processor a, int n);
void random(processor a, int n);
void input(processor a, int n);
void start_add(processor a, int n);
void end_add(processor a, int n);
void output(int cnt);


void menu(processor a, int n)
{
    int u;
    cout << "\n\n выберите действие:\n";
    cout << " 1 - Ввод с экрана и запись в файл;\n";
    cout << " 2 - Ввод случайным образом и запись в файл;\n";
    cout << " 3 - Добавить запись в начало файла;\n";
    cout << " 4 - Добавить запись в конец файла;\n";
    cout << " 5 - Печать одной записи из файла по номеру;\n";
    cout << " 6 - Чтение всех структур последовательно из файла и печать;\n";
    cout << " 0 - выход из программы.\n";

    cin >> u;

    switch(u)
    {

    case 1:
    {
        input(a, n);
        menu(a, n);
        break;
    }
    case 2:
    {
        random(a, n);
        menu(a, n);
        break;
    }
    case 3:
    {
        start_add(a, n);
        menu(a, n);
        break;
    }
    case 4:
    {
        end_add(a, n);
        menu(a, n);
        break;
    }
    case 5:
    {
        cout << "\n введите номер записи: \n";
        cin >> u;
        output(u);
        menu(a, n);
        break;
    }
    case 6:
    {
        foutput(a, n);
        menu(a, n);
        break;
    }
    case 0:
    {
        break;
    }
    }
}
