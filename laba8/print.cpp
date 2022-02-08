#include <iostream>
#include <string>
#include <cstring>

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


void print(slist a)
{
    if (a.first == NULL)
    {
        cout << "������ ������!\n";
        return;
    }
    node* p = a.first;

    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("|�������������� ����                                                                |\n");
    printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|���������              |�������(Mgz)             |RAM(Mb)            |���          |\n");
    printf("|- - - - - - - - - - - -|- - - - - - - - - - - - -|- - - - - - - - - -|- - - - - - -|\n");
    while (p)
    {
        const char *c = p->cpu.c_str() ;
        int cs = p->cpu.size();
        char tmp[cs + 1];
        strcpy(tmp, c);
        printf("|%-22s | %-23d |                   | %-11c |\n", tmp, p->freaq, p->type);
        p = p->next;
    }
    printf("\n|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|���: C - CISC - ���������, R - RISC - ���������                                    |\n");
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    cout << endl;
}
