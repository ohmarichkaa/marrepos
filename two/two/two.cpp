#include <iostream>
#include<cmath>
using namespace std;

void solution(double* square, double* volume)
{
    double H = 0.0 , R = 0.0;
    while (H == 0)
    {
        cout << "\nEnter height, please (height must not be 0.0): ";
        cin >> H;
        if (H == 0)
            cout << "\nTry again!\n";
    }

    while (R == 0)
    {
        cout << "\nEnter base radius, please (base radius must not be 0.0): ";
        cin >> R;
        if (R == 0)
            cout << "\nTry again!";
    }

    *square = R * R * acos(-1.0);
    *volume = *square * H / 3;
}


int main()
{
    double square1, square2;
    double volume1, volume2;
    cout << "First cone: \n";
    solution(&square1, &volume1);
    cout << "\nsquare = " << square1 << ";  volume = " << volume1;
    cout << ".\n\nSecond cone: \n";
    solution(&square2, &volume2);
    cout << "\nsquare = " << square2 << ";  volume = " << volume2;
    cout << ".\n";
    return 0;
}
