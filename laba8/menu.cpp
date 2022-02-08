#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    string cpu;
    int freaq;
    char type;
    node *next;
};

struct slist
{
    node *first;
    node *last;

    slist():first(NULL), last(NULL) {}
};

void delete_el(slist a, int u);
void clear(slist a);
void create(slist a, int u);
void add_node(slist a, int num);
void print(slist a);
void fprint();


void menu (slist a)
    {
        int u;

        cout << "\n �������� ��������:\n";
        cout << " 1 - ������� ������;\n";
        cout << " 2 - �������� ������� � ��������� �����;\n";
        cout << " 3 - ������� ��������� ������� �� ������;\n";
        cout << " 4 - ����� �� ��������;\n";
        cout << " 5 - ���������� ������;\n";
        cout << " 6 - �������� ������ � ����;\n";
        cout << " 7 - ����� ������;\n";
        cout << " 8 - ������� ����� ������ �� �����;\n";
        cout << " 0 - ����� �� ���������.\n";

        cin >> u;

        switch (u)
        {
        case 1:
        {
            create(a, 1);
            menu(a);
            break;
        }
        case 2:
        {
            cout << "\n������� ����� ������������ �������� ";
            cin >> u;
            add_node(a, u);
            menu(a);
            break;
        }
        case 3:
        {
            cout << "\n������� ����� ���������� �������� ";
            int l;
            cin >> l;
            delete_el(a, l);
            menu(a);
            break;
        }
        case 4:
        {
            cout << " 1 - ����� �� ��������;\n";
            cout << " 2 - ����� �� �������;\n";
            cout << " 3 - ����� �� ����;\n";
            cin >> u;
          //  search_el(u);
            break;
        }
        case 5:
        {

        }
        case 6:
        {
            clear(a);
            create(a, 1);
            break;
        }
        case 7:
        {
            print(a);
            menu(a);
            break;
        }
        case 8:
        {
            clear(a);
            create(a, 2);
            menu(a);
            break;
        }
        case 0:
        {
            break;
        }
    }}
