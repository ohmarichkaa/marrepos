#include <iostream>
using namespace std;


double Calc(double A, double B, int Op)
{
    switch(Op)
    {
    case 1:
    {
        return A + B;
    }
    case 2: 
    {
        return A - B;
    }
    case 3:
    {
        return A * B;
    }
    case 4:
    {
        return A / B;
    }
    default:
        cout << "Ooop! Something wrong!!/n";
        break;
    }
}


int main()
{
    double A = 0.0, B = 0.0;
    while (A == 0)
    {
        cout << "\nEnter A, please (A must not be 0.0): ";
        cin >> A;
        if(A == 0)
            cout << "\nTry again!\n";
    }
    
    while (B == 0)
    {
        cout << "\nEnter B, please (B must not be 0.0): ";
        cin >> B;
        if (B == 0)
            cout << "\nTry again!";
    }

    cout << "\nA + B = " << Calc(A, B, 1);
    cout << "\nA - B = " << Calc(A, B, 2);
    cout << "\nA * B = " << Calc(A, B, 3);
    cout << "\nA / B = " << Calc(A, B, 4);

    cout << "\n\nB - A = " << Calc(B, A, 2);
    cout << "\nB / A = " << Calc(B, A, 4);

    return 0;

}
