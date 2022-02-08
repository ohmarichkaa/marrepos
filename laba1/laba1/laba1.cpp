#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

struct student
{
    string surname;
    int age;
    double avs;
};


void input(student a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].surname >> a[i].age >> a[i].avs;
    }
}


void random(student a[], int n)
{
    static const char alphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++)
    {
        a[i].surname = alphabet[rand() % 26];
        int cnt = rand() % 5 + 5;
        // cout << cnt << "  ";
        for (int u = 0; u < cnt; u++)
        {
            a[i].surname += alphabet[rand() % 26 + 26];
        }
        a[i].age = rand() % 4 + 18;
        a[i].avs = 3.0 + (5.0 - 3.0) * (double)rand() / (double)RAND_MAX;
    }
}


void output(student a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].surname << setw(10) << a[i].age << setw(10) << a[i].avs << endl;
    }
}


void menu(student a[], int n)
{
    cout << 12 + n << endl;
    random(a, n);
    cout << "surname:" << setw(10) << "age:" << setw(10) << "average score:" << endl;
    output(a, n);
}

int main()
{
    int n;
    cin >> n;
    student mas[100];
    menu(mas, n);

}
