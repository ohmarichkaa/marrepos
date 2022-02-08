#include <iostream>

int merger(int* mas1, int* mas2, int* mas, int n1, int n)
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


int sort(int* mas, int n)
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
