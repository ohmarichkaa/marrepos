#include "Functions.h"


void PrintMatrix(int Matrix[][SIZE], int c, int r)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
			cout << Matrix[i][j] << "\t";
			cout << "" << endl;
	}

}

void FwriteMatrix(string path, int Matrix[][SIZE], int c, int r)
{
	ofstream ofs;
	ofs.open(path);
	if (!ofs.is_open())	return;
	
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
			ofs << Matrix[i][j] << "\t";

			ofs << endl;
	}

	ofs.close();
}

void FreadMatrix(string path, int Matrix[][SIZE], int c, int r)
{

	ifstream ifs;
	ifs.open(path);
	if (!ifs.is_open())	return;

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
			ifs >> Matrix[i][j];
	}
	ifs.close();

}