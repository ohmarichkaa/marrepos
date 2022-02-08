#include <iostream>
//5.	Даны два массива: mas1[N] и mas2[M].
//Создать третий массив, в который переписать элементы массива mas1, а затем mas2. Полученный массив упорядочить по возрастанию.
using namespace std;

void input(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

    }
}


void output(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";

    }
}


int merger(int *mas1, int *mas2, int *mas, int n1, int n)
{
    for (int i = 0; i < n1; i++)
    {
        mas[i] = mas1[i];
    }
    int k = 0;
    for (int i = n1; i < n; i++)
    {
        mas[i] = mas2[k];
        k++;
    }
}


int sort(int *mas, int n)
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int u = i + 1; u < n; u++)
        {
           if (mas[i] > mas[u])
           {
               tmp = mas[i];
               mas[i] = mas[u];
               mas[u] = tmp;
           }
        }
    }

}


int main()
{
    int n1, n2;
    cout << "enter n1 \n";
    cin >> n1;
    cout << "enter n2 \n";
    cin >> n2;
   int mas1[n1];
   int mas2[n2];
   int n = n1 + n2;
   int mres[n];
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
