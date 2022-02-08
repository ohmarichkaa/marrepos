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
    cout<<"������� ����� � ����: "<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "������� ����: menu.cpp; ������� �������: menu " << endl;
#endif

    int u;
    cout << "\n �������� ��������:\n";
    cout << " 1 - ����������;\n";
    cout << " 2 - ����� ������ ������� ��������;\n";
    cout << " 0 - ����� �� ���������.\n";

    cin >> u;

    switch(u)
    {

    case 1:
    {
        cout << "\n";
        cout << " 1 - ����������� �� �������� ���������;\n";
        cout << " 2 - ����������� �� �������� ���������;\n";
        cout << " 3 - ����������� �� �������� ����� ���������.\n";

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
        cout<<"������� ����� � ����: "<<asctime(timeinfo)<<endl;
        cin.get();
#else
        cout << "������� ����: menu.cpp; ������� �������: menu " << endl;
#endif
        break;
    }
    }

}
