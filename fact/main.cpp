#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int arr[6][2];
    arr[0][1] = 26;
    arr[1][1] = 16;
    arr[2][1] = 20;
    arr[3][1] = 12;
    arr[4][1] = 22;
    arr[5][1] = 12;
    arr[0][0] = 42;
    arr[1][0] = 18;
    arr[2][0] = 18;
    arr[3][0] = 22;
    arr[4][0] = 10;
    arr[5][0] = 8;
   double arr2[12] = {35.50442478,
17.75221239 ,
19.84070796,
17.75221239,
16.7079646,
10.44247788,
32.49557522,
16.24778761,
18.15929204,
16.24778761,
15.2920354,
9.557522124};
double result = 0;
int k = 0;
   for (int j = 0; j < 2; j++)
   {
       for (int i = 0; i < 6; i++)
       {
            result += (arr[i][j] - arr2[k]) * (arr[i][j] - arr2[k]) / arr2[k];
            k++;
        }
   }
   cout << sqrt(result / (result + 226)) ;


}
