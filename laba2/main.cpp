#include <iostream>
#include <ctime>

#define PRINT_TYPE
using namespace std;

struct processor
{
    string cpu;
    int freaq;
    char type;
};


void menu(processor a[], int n);
void input(processor a[], int n);
void random(processor a[], int n);

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    int n;
    cout << " Введите количество студентов:  ";
    cin >> n;
    processor mas[100];

#ifdef PRINT_TYPE
    random(mas, n);
#endif
#ifndef PRINT_TYPE
    input(mas, n);
#endif // PRINT_TYPE

    menu(mas, n);
}
