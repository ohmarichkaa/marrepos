#include<iostream>
using namespace std;

int main()
{
	int a, b, b2;
	cin >> a;
	cin >> b;
	cin >> b2;
	int **m = new int*[a];
	int** m2 = new int* [b];
	int** res = new int* [a];

	for (int i = 0; i < a; i++)
	{
		m[i] = new int[b];
	}

	for (int i = 0; i < a; i++)
	{
		res[i] = new int[b2];
	}

	for (int i = 0; i < a; i++)
	{
		for (int u = 0; u < b; u++)
		{
			cin >> m[i][u];
		}
	}


	for (int i = 0; i < b; i++)
	{
		m2[i] = new int[b2];
	}

	for (int i = 0; i < b; i++)
	{
		for (int u = 0; u < b2; u++)
		{
			cin >> m2[i][u];
		}
	}

	for (int i = 0; i < a; i++)
	{
		
		for (int u = 0; u < b2; u++)
		{
			int sum = 0;
			for (int j = 0; j < b; j++)
			{
				sum += m[i][j] * m2[j][u];
			}
			res[i][u] = sum;
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int u = 0; u < b2; u++)
		{
			cout << res[i][u] << "  ";
		}
	}

}