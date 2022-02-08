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
    cout << "\n\n �������� ��������:\n";
    cout << " 1 - ���� � ������ � ������ � ����;\n";
    cout << " 2 - ���� ��������� ������� � ������ � ����;\n";
    cout << " 3 - �������� ������ � ������ �����;\n";
    cout << " 4 - �������� ������ � ����� �����;\n";
    cout << " 5 - ������ ����� ������ �� ����� �� ������;\n";
    cout << " 6 - ������ ���� �������� ��������������� �� ����� � ������;\n";
    cout << " 0 - ����� �� ���������.\n";

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
        cout << "\n ������� ����� ������: \n";
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
