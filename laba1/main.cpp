#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>
#include <cstring>
using namespace std;

struct processor
{
    string cpu;
    int freaq;
    char type;
};


void input(processor a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nВведите название процессора: ";
        cin >> a[i].cpu;
        cout << "\nВведите частоту: ";
        cin >> a[i].freaq;
        cout << "\nВведите тип процессора: ";
        cin>> a[i].type;
    }
}


void random(processor a[], int n)
{
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
}


void output(processor a[], int n)
{
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("|Характеристики ПЭВМ                                                                |\n");
    printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|Процессор              |Частота(Mgz)             |RAM(Mb)            |Тип          |\n");
    printf("|- - - - - - - - - - - -|- - - - - - - - - - - - -|- - - - - - - - - -|- - - - - - -|\n");
    for (int i = 0; i < n; i++)
    {
        const char *s = a[i].cpu.c_str() ;
        int cs = a[i].cpu.size();
        char tmp[cs + 1];
        strcpy(tmp, s);
        printf("|%-22s | %-23d |                   | %-11c |\n", tmp, a[i].freaq, a[i].type);
    }
    printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|Тип: C - CISC - процессор, R - RISC - процессор                                    |\n");
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
}


void msort(processor a[], int n, int k)
{
    string tmp;
    int tmp1;
    char tmp2;

    switch(k)
    {
    case 1:
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i].cpu > a[j].cpu)
                {
                    tmp = a[i].cpu;
                    a[i].cpu = a[j].cpu;
                    a[j].cpu = tmp;

                    tmp1 = a[i].freaq;
                    a[i].freaq = a[j].freaq;
                    a[j].freaq = tmp1;

                    tmp2 = a[i].type;
                    a[i].type = a[j].type;
                    a[j].type = tmp2;
                }
            }
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i].freaq > a[j].freaq)
                {
                    tmp1 = a[i].freaq;
                    a[i].freaq = a[j].freaq;
                    a[j].freaq = tmp1;

                    tmp = a[i].cpu;
                    a[i].cpu = a[j].cpu;
                    a[j].cpu = tmp;

                    tmp2 = a[i].type;
                    a[i].type = a[j].type;
                    a[j].type = tmp2;
                }
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i].type > a[j].type)
                {
                    tmp2 = a[i].type;
                    a[i].type = a[j].type;
                    a[j].type = tmp2;

                    tmp = a[i].cpu;
                    a[i].cpu = a[j].cpu;
                    a[j].cpu = tmp;

                    tmp1 = a[i].freaq;
                    a[i].freaq = a[j].freaq;
                    a[j].freaq = tmp1;
                }
            }
        }
        break;
    }
    }
}


void menu(processor a[], int n)
{
    int u;
    cout << "\n выберите действие:\n";
    cout << " 1 - заполнить  массив структур с клавиатуры;\n";
    cout << " 2 - рандомное заполнение;\n";
    cout << " 3 - сортировка;\n";
    cout << " 4 - вывод данных массива структур;\n";
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
        cout << "\n";
        cout << " 1 - сортировать по названиям;\n";
        cout << " 2 - сортировать по частоте;\n";
        cout << " 3 - сортировать по типу.\n";

        cin >> u;
        msort(a, n, u);
        menu(a, n);
        break;
    }
    case 4:
    {
        output(a, n);
        menu(a, n);
        break;
    }
    case 0:
    {
        break;
    }
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << " Введите количество данных:  ";
    cin >> n;
    processor mas[n];
    menu(mas, n);
}
