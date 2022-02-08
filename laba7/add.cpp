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


void start_add(processor a, int n)
{
    ofstream data1("data1.txt");

     cout << "\n¬ведите название процессора: ";
    cin >> a.cpu;
     cout << "\n¬ведите частоту: ";
    cin >> a.freaq;
     cout << "\n¬ведите тип процессора: ";
    cin>> a.type;
    data1 << "cpu: " << a.cpu << "\t\t freaq: "  << a.freaq << "\t type: " << a.type << endl;
    fstream data("data.txt");
    string s;

    getline(data, s);
    data1 << s;
    while(data)
    {
        getline(data, s);
        data1 << "\n" << s;
    }


    data.close();
    data1.close();

    remove("data.txt");
    rename("data1.txt", "data.txt");
}


void end_add(processor a, int n)
{
    ofstream data("data.txt");

    cout << "\n¬ведите название процессора: ";
    cin >> a.cpu;
     cout << "\n¬ведите частоту: ";
    cin >> a.freaq;
     cout << "\n¬ведите тип процессора: ";
    cin>> a.type;
    data << "cpu: " << a.cpu << "\t\t freaq: "  << a.freaq << "\t type: " << a.type << endl;

    data.close();
}



