#include <iostream>
#include <ctime>
#include <cstring>
//#define DEBUG

using namespace std;

struct processor
{
    string cpu;
    int freaq;
    char type;
};


void output(processor a[], int n)
{
#if defined DEBUG
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: output.cpp; текущая функция: output " << endl;
#endif
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("|Характеристики ПЭВМ                                                                |\n");
    printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|Процессор              |Частота(Mgz)             |RAM(Mb)            |Тип          |\n");
    printf("|- - - - - - - - - - - -|- - - - - - - - - - - - -|- - - - - - - - - -|- - - - - - -|\n");
    for (int i = 0; i < n; i++)
    {
        const char *s = a[i].cpu.c_str() ;
        int cs = a[i].cpu.size();
        char tmp[cs + 1];
        strcpy(tmp, s);
        printf("|%-22s | %-23d |                   | %-11c |\n", tmp, a[i].freaq, a[i].type);
    }
    printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|Тип: C - CISC - процессор, R - RISC - процессор                                    |\n");
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
#if defined DEBUG
    seconds = time(NULL);
    timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: output.cpp; текущая функция: output " << endl;
#endif
}
