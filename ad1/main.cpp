#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define ERROR_FILE_OPEN -3
using namespace std;


void die (int code, const char* error)
{
    cout << error;
    exit(code);
}



void input(int array[], int n)
{
    FILE *data = fopen("data1.txt", "r");
    if (data == NULL)
        die(ERROR_FILE_OPEN, " Error of opening of a output-file");

    int i = 0;
    int x;
    while(fscanf(data,"%d", &x)!= EOF)
    {
        array[i] = x;
        i++;

    }
    fclose(data);
}


int count(int array[], int n, int val)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(array[i] == val)
        {
            count++;
        }
    }
    return count;
}


double sum(int array[], int n, int a, double p, int ix)
{
    double sum = 0.0;
    long double c = 1.0;
    double p_cnt;
    double q = 1 - p;

    for (int i = ix; i < n; i++)
    {
        c = 1.0;
        p_cnt = 1;
        q = 1 - p;

        for (int u = 1; u < i + 1; u++)
        {
            c /= u;
            p_cnt *= p;
        }

        for (int j = 1; j < n + 1; j++)
        {
            c *= j;
        }
        for (int j = 1; j < n + 1 - i; j++)
        {
            c /= j;
        }

        for (int u = 1; u < n - i; u++)
        {
            q *= (1 - p);
        }
         //cout << sum1 << "  ";
        sum += c * q * p_cnt;
         //cout << q << "  " << c1 << "  " << p_cnt << endl;
    }
    return sum;
}


void bzr (int array[], int n, int a, double p)
{
    int cnt = count(array, n, 3);

    long double P = 0.0;
    if(sum(array, n, a, p, 0) < sum(array, n, a, p, cnt))
    {
        P = sum(array, n, a, p, 0) * 2;
    }
    else
    {
        P = sum(array, n, a, p, cnt) * 2;
    }
    cout << " P = " << P << ".\n";

    if(P < 0.95)
        cout << " hypothesis is rejected\n";
    else
        cout << " hypothesis is accepted\n";
}


void zr (int array[], int n, int a, double p)
{
    double preal;
    preal = 1.0 * count(array, n, 3) / n;
   // cout << "\n pr " << preal;
    double z = (preal - p)/(sqrt(p * (1 - p)/ n));
    cout << "\n Z-disribution " << z;

    double z0 = 1.96;
    cout << "\n z-value for 95 confidence interval = " << z0 << ".\n";

    double x = p - z0 * sqrt((1 - p) * p / n);
    double y = p + z0 * sqrt((1 - p) * p / n);

    printf("\n confidence interval (%f, %f).\n", x, y);
}


void normx1(int array[], int n, double p)
{
    int cnt = count(array, n, 3);
    double e1 = n * p;
    double xi2 = (cnt - e1) * (cnt - e1) / e1 + (n - cnt - e1) * (n - cnt - e1) / e1;
    cout << " chi-squared value = " << xi2 << ".\n";
    cout << " table chi-squared value = " << 0.004 << " (for p-value = 0,95).\n";

    if(xi2 > 0.004)
         cout << " hypothesis is rejected\n";
    else
        cout << " hypothesis is accepted\n";
}


void normx2(int array[], int n, int cnt[], double p[])
{
    double e1[5];
    for (int i = 0; i < 5; i++)
    {
        e1[i] = n * p[i];
    }


    double xi2 = 0;

    for (int i = 0; i < 5; i++)
    {
      xi2 += (cnt[i] - e1[i]) * (cnt[i] - e1[i]) / e1[i];
    }

    cout << " chi-squared value = " << xi2 << ".\n";
    cout << " table chi-squared value = " << 0.71 << " (for p-value = 0,95).\n";
    if(xi2 > 0.71)
         cout << " hypothesis is rejected\n";
    else
        cout << " hypothesis is accepted\n";
}


int main()
{
    double a = 1 - 0.95;
    int array[200];
    int n = 200;
    cout << " total number of patients " << n << ".\n";

    double p = 0.5;
    input (array, n);
    cout << " number of middle-income patients is " << count (array, n, 3) << " which is " << 1.0 * count (array, n, 3) / n << " of the total number.\n";
    cout << "\n";
    cout << " H0 : p0 = 0,5, where level of importance = 0,95. \n\n";
    bzr(array, n, a, p);
    zr(array, n, a, p);
    cout << "\n";
    normx1(array, n, p);
    cout << "\n";

    cout << "\n H0 : p0 = 0,1, p1 = 0,2, p3 = 0,5, p4 = 0,1, p5 = 0,1, where level of importance = 0,95. \n\n";

    double p1[5] = {0.1, 0.2, 0.5, 0.1, 0.1};
    int cnt[5];
    for (int i = 0; i < 5; i++)
    {
        cnt[i] = count(array, n, i + 1);
    }

    normx2(array, n, cnt, p1);
}
