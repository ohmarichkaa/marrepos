#include <iostream>

using namespace std;

/*1. ���� � ������ � ������ � ����.
2.  ���� ��������� ������� � ������ � ����.
3. �������� ������ � ������ �����.
4. �������� ������ � ����� �����.
5. ������ ����� ������ �� ����� �� ������.
6. ������ ���� �������� ��������������� �� ����� � ������.
7. ����� �� ���������.*/

struct processor
{
    string cpu;
    int freaq;
    char type;
};


void menu(processor a, int n);


int main()
{
     setlocale(LC_ALL, "Rus");
    int n;
    cout << " ������� ���������� ������:  ";
    cin >> n;
    processor info;
    menu(info, n);

}
