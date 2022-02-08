#include <iostream>
#include <locale.h>
#include<cstring>
#include <string>
using namespace std;


int count(char* str, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
            cnt++;
    }
    return cnt;
}


void word(char* str, int n)
{
    cout << "Enter symbol \n";
    char x;
    cin >> x;
    int u = 1;
    int tmp[30];
    tmp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 32)
        {
            tmp[u] = i + 1;
            u++;
        }
    }
    tmp[u] = n;
    u++;
    int id = tmp[1];
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < u; i++)
    {
        cnt1 = 0;
        for (int j = tmp[i]; j < tmp[i + 1]; j++)
        {
            if (str[j] == x)
                cnt1++;
        }
        if (cnt < cnt1)
        {
            cnt = cnt1;
            id = i + 1;
        }
    }

    for (int i = tmp[id - 1]; i < tmp[id]; i++)
    {
        cout << str[i];
    }
}


int main()
{
    setlocale(LC_ALL, "");
    string s;
    getline(cin, s);
    int n = s.length() + 1;
    char* str = new char[n];
    const char* s1 = s.c_str();
    strcpy_s(str, n, s1);
    
    for (int i = 0; i < n; i++)
        cout << str[i];
    cout << "\n\nresult : ";
    cout << count(str, n);
    cout << "\n\nresult : ";
   word(str, n);

}

