#include <iostream>
#include <fstream>
#include <string>


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

void fprint(slist a)
{
    ofstream data("data1.txt");
    if (a.first == NULL)
    {
        cout << "список пустой!\n";
        return;
    }
    node* p = a.first;
    while (p)
    {
        data << "cpu: " << p->cpu << "\t\t freaq: "  << p->freaq << "\t type: " << p->type << endl;
    }
    cout << endl;
    data.close();
}
