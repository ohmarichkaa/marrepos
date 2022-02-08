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

void deleteel(slist a, int u)
{
    node* p = a.first;
    if (u == 1)
    {
        a.first = p->next;
        delete(p);
    }
    else
    {
        while (u > 2)
        {
            p = p->next;
            u--;
        }
        node* x = p ->next;
        p->next = x->next;
        delete(x);
    }
}
