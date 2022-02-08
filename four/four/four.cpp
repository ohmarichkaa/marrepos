#include <iostream>
#include <locale.h>
#include <windows.h>
#include <fstream>
using namespace std;

int len()
{
    char x;
    int l = 0;
    ifstream data("data.txt");
    
    while (!data.eof())
    {
        data >> x;
        l++;
    }
    data.close();
    return l - 1;
}


void fread(char* str)
{
    int l = 0;
    ifstream data("data.txt");
    setlocale(LC_ALL, "Rus");
    
    while (!data.eof())
    {
        data >> str[l];
        l++;
    }
    data.close();
}


int count(char* str, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            cnt++;

        if (str[i] >= 'À' && str[i] <= 'ÿ')
            cnt++;
    }
    return cnt;
}



int main()
{     
    setlocale(LC_ALL, "");
    int n = len();
    char* str = new char[n];
    fread(str);
       
    for (int i = 0; i < n; i++)
        cout << str[i];
    cout << "\n\nresult : ";
    cout << count(str, n);

}

