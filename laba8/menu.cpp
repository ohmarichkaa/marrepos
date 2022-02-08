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

        cout << "\n выберите действие:\n";
        cout << " 1 - создать список;\n";
        cout << " 2 - добавить элемент в указанное место;\n";
        cout << " 3 - удалить указанный элемент из списка;\n";
        cout << " 4 - поиск по критерию;\n";
        cout << " 5 - сортировка списка;\n";
        cout << " 6 - записать список в файл;\n";
        cout << " 7 - вывод списка;\n";
        cout << " 8 - создать новый список из файла;\n";
        cout << " 0 - выход из программы.\n";

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
            cout << "\nвведите номер добавляемого элемента ";
            cin >> u;
            add_node(a, u);
            menu(a);
            break;
        }
        case 3:
        {
            cout << "\nвведите номер удаляемого элемента ";
            int l;
            cin >> l;
            delete_el(a, l);
            menu(a);
            break;
        }
        case 4:
        {
            cout << " 1 - поиск по названию;\n";
            cout << " 2 - поиск по частоте;\n";
            cout << " 3 - поиск по типу;\n";
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
