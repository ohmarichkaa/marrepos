#include <iostream>
#include <string>

using namespace std;


struct processor
{
    string cpu;
    int freaq;
    char type;
};

void msort(processor a[], int n, int k)
{
#if defined DEBUG
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: sort.cpp; текущая функция: msort " << endl;
#endif

    string tmp;
    int tmp1;
    char tmp2;
    switch(k)
    {
    case 1:
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i].cpu > a[j].cpu)
                {
                    tmp = a[i].cpu;
                    a[i].cpu = a[j].cpu;
                    a[j].cpu = tmp;

                    tmp1 = a[i].freaq;
                    a[i].freaq = a[j].freaq;
                    a[j].freaq = tmp1;

                    tmp2 = a[i].type;
                    a[i].type = a[j].type;
                    a[j].type = tmp2;
                }
            }
        }
        break;
    }

    case 2:
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i].freaq > a[j].freaq)
                {
                    tmp1 = a[i].freaq;
                    a[i].freaq = a[j].freaq;
                    a[j].freaq = tmp1;

                    tmp = a[i].cpu;
                    a[i].cpu = a[j].cpu;
                    a[j].cpu = tmp;

                    tmp2 = a[i].type;
                    a[i].type = a[j].type;
                    a[j].type = tmp2;
                }
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i].type > a[j].type)
                {
                    tmp2 = a[i].type;
                    a[i].type = a[j].type;
                    a[j].type = tmp2;

                    tmp = a[i].cpu;
                    a[i].cpu = a[j].cpu;
                    a[j].cpu = tmp;

                    tmp1 = a[i].freaq;
                    a[i].freaq = a[j].freaq;
                    a[j].freaq = tmp1;
                }
            }
        }
        break;
    }
    }
#if defined DEBUG
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    cout<<"Текущее время и дата:"<<asctime(timeinfo)<<endl;
    cin.get();
#else
    cout << "Текущий файл: sort.cpp; текущая функция: msort " << endl;
#endif
}
