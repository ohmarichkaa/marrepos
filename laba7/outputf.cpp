#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
using namespace std;


struct processor
{
    string cpu;
    int freaq;
    char type;
};


void output(int cnt)
{
    ifstream data("data.txt");
    char s[255];

    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("|Характеристики ПЭВМ                                                                |\n");
    printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|Процессор              |Частота(Mgz)             |RAM(Mb)            |Тип          |\n");
    printf("|- - - - - - - - - - - -|- - - - - - - - - - - - -|- - - - - - - - - -|- - - - - - -|\n");
    while(cnt != 0)
    {
        data.getline(s, 255);
        cnt--;
    }
        data >> s;
        data >> s;
        if (!data.eof())
        {
            printf("|%-22s | ", s);
        }
        data >> s;
        data >> s;
        if (!data.eof())
        {
            printf("%-23s |                   | ", s);
        }
        data >> s;
        data >> s;
        if (!data.eof())
        {
            printf("%-11s |\n", s);
        }
    printf("\n|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|Тип: C - CISC - процессор, R - RISC - процессор                                    |\n");
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    data.close();
}


void foutput(processor a, int n)
{
    ifstream data("data.txt");
    char s[255];

    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("|Характеристики ПЭВМ                                                                |\n");
    printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|Процессор              |Частота(Mgz)             |RAM(Mb)            |Тип          |\n");
    printf("|- - - - - - - - - - - -|- - - - - - - - - - - - -|- - - - - - - - - -|- - - - - - -|\n");
    while(!data.eof())
    {
        data >> s;
        data >> a.cpu;
        data >> s;
        data >> a.freaq;
        data >> s;
        data >> a.type;

        const char *c = a.cpu.c_str() ;
        int cs = a.cpu.size();
        char tmp[cs + 1];
        strcpy(tmp, c);
        if (!data.eof())
            printf("|%-22s | %-23d |                   | %-11c |\n", tmp, a.freaq, a.type);
    }
    printf("\n|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|Тип: C - CISC - процессор, R - RISC - процессор                                    |\n");
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

    data.close();
}


