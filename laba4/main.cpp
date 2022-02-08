#include <iostream>
using namespace std;


void input(int* a, int n);
void output(int* a, int n);
int merger(int* mas1, int *mas2, int *mas, int n1, int n);
int sort(int* mas, int n);

int main()
{
    int n1, n2;
    cout << "enter n1 \n";
    cin >> n1;
    cout << "enter n2 \n";
    cin >> n2;
    int *mas1 = new int[n1];
    int *mas2= new int[n2];
    int n = n1 + n2;
    int *mres = new int[n];
    cout << "enter array1 \n";
    input(mas1, n1);
    cout << "enter array2 \n";
    input(mas2, n2);
    cout << "merger \n";
    merger(mas1, mas2, mres, n1, n);
    output(mres, n);
    cout << "\nsort \n";
    sort(mres, n);
    output(mres, n);
}
