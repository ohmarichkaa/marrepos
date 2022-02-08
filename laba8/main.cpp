#include <iostream>

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


void menu(slist processor);

int main()
{
    setlocale(LC_ALL, "Rus");
    slist processor;
    menu(processor);
    return 0;
}
