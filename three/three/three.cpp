#include <iostream>
using namespace std;



void random_in(int** array, int N, int M)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            array[i][j] = rand() % 99 + 1;
    }
}


void input(int** array, int N, int M)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> array[i][j];
}


void minmax (int * array, int N, int* max, int* min)
{
    int Max = array[0];
    *min = 0;
    int Min = array[0];
    *max = 0;
    for (int i = 1; i < N; i++)
    {
        if (Min > array[i])
        {
            *min = i;
            Min = array[i];
        }

        if (Max < array[i])
        {
            *max = i;
            Max = array[i];
        }
    }
}


void swap_el(int** array, int M, int N)
{
    int min, max;

    for(int i = 0; i < M; i++)
    {
        minmax(array[i], N, &max, &min);
        int tmp = array[i][max];
        array[i][max] = array[i][min];
        array[i][min] = tmp;
    }
}


void output(int** array, int N, int M)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%5d ", array[i][j]);
        cout << endl;
    }
}


int main()
{
    int M = 0, N = 0;

    while (M == 0)
    {
        cout << "\nEnter M, please (M must not be 0.0): ";
        cin >> M;
        if (M == 0)
            cout << "\nTry again!\n";
    }

    while (N == 0)
    {
        cout << "\nEnter N, please (N must not be 0.0): ";
        cin >> N;
        if (N == 0)
            cout << "\nTry again!";
    }

    int** mas = new int*[M];
    for (int i = 0; i < M; i++)
    {
        mas[i] = new int[N];
    }
     
   // random_in(mas, N, M);
    cout << "\nEnter array, please:\n";
    input(mas, N, M);
    output(mas, N, M);
    cout << "\n\n";
    swap_el(mas, M, N);
    output(mas, N, M);

    for (int i = 0; i < M; i++)
    {
        delete [] mas[i];
    }
    delete [] mas;
    return 0;

}
