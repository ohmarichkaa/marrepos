#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>
#include <fstream>

using namespace std;

struct processor
{
    string cpu;
    int freaq;
    char type;
};



void input(processor a, int n)
{
    ofstream data("data.txt");

    for (int i = 0; i < n; i++)
    {    cout << "\n¬ведите название процессора: ";
        cin >> a.cpu;
        cout << "\n¬ведите частоту: ";
        cin >> a.freaq;
        cout << "\n¬ведите тип процессора: ";
        cin >> a.type;
        data << "cpu: " << a.cpu << "\t\t freaq: "  << a.freaq << "\t type: " << a.type << endl;
    }
    data.close();
}


void random(processor a, int n)
{
    static const char alphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        static const char t[] =
        "CR";
        srand(time(NULL));
        ofstream data("data.txt");
    for (int i = 0; i < n; i++)
    {
        a.cpu = alphabet[rand() % 26];
        int cnt = rand() % 5 + 5;
        for (int u = 0; u < cnt; u++)
        {
            a.cpu += alphabet[rand() % 26 + 26];
        }
        a.freaq = rand() % 3000 + 1000;

        a.type = t[rand() % 2];

        data << "cpu: " << a.cpu << "\t\t freaq: "  << a.freaq << "\t type: " << a.type << endl;
    }
    data.close();
}

