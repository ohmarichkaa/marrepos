#include <iostream>
#include <string>
#include <fstream>
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

void clear(slist a)
{
    node* p = a.first;
    node* x = p->next;
    while (x != a.last)
    {
        p->next = x->next;
        delete(x);
        x = p->next;

    }
    a.first = NULL;
    a.last = NULL;
    cout << "cписок очищен!!!";
}


void end_add_node(slist a, string cpu, int freaq, char type)
{
    node *tmp = new node;
    tmp->cpu = cpu;
    tmp->freaq = freaq;
    tmp->type = type;
    tmp->next = NULL;

    if(a.first == NULL)
    {
        a.first = tmp;
        a.last = tmp;
    }
    else
    {
        a.last->next = tmp;
        a.last = a.last->next;
    }
}


void create(slist a, int u)
{
    string cpu;
    int freaq;
    char type;
    if (u == 1)
    {
        cout << " введите количество элементов в создаваемом списке  ";
        int size;
        cin >> size;
        cout << "\n введите элементы списка(название, частота, тип): ";
        for (int i = 0; i < size; i++)
        {
            cin >> cpu;
            cin >> freaq;
            cin >> type;
            end_add_node(a, cpu, freaq, type);
        }
    }
    else
    {
        ifstream data("data.txt");
        char s[255];
        while(!data.eof())
        {
            data >> s;
            data >> cpu;
            data >> s;
            data >> freaq;
            data >> s;
            data >> type;
            end_add_node(a, cpu, freaq, type);
        }

        data.close();
    }
}


void add_node(slist a, int num)
{
    string cpu;
    int freaq;
    char type;
    cout << "\n введите элементы списка(название, частота, тип): ";
    cin >> cpu;
    cin >> freaq;
    cin >> type;
    node *tmp = new node;
    node *p = a.first;
    tmp->cpu = cpu;
    tmp->freaq = freaq;
    tmp->type = type;

    for (int i = 0; i < num - 2; i++)
    {
        p = p->next;
    }

    tmp->next = p->next;
    p->next = tmp;
}
