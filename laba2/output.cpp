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
    cout<<"������� ����� � ����:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "������� ����: output.cpp; ������� �������: output " << endl;
#endif
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
    printf("|�������������� ����                                                                |\n");
    printf("|- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
    printf("|���������              |�������(Mgz)             |RAM(Mb)            |���          |\n");
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
    printf("|���: C - CISC - ���������, R - RISC - ���������                                    |\n");
    printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
#if defined DEBUG
    seconds = time(NULL);
    timeinfo = localtime(&seconds);
    cout<<"������� ����� � ����:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "������� ����: output.cpp; ������� �������: output " << endl;
#endif
}
