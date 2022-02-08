#include "Graph.h"

int main()
{
	setlocale(LC_ALL, "rus");
	bool* b = new bool[N]();
	Graph* ob = new Graph();

	int temp = 0;
	for (;;)
	{
		int c = 0;
		cout << "1 - ��������� ������� ��������� �������\n";
		cout << "2 - ��������� ������� ������������� �������\n";
		cout << "3 - ��������� ������ ����� �������\n";
		cout << "4 - ��������� ������ ��������� �������\n";
		cout << "5 - ��������� ��� ���� �������� ����� �������������\n";
		cout << "\n\n";
		cout << "6 - ������� ��� ���� �������� ����� �� �����\n";
		cout << "7 - �������� ��� ���� �������� ����� � ����\n";
		cout << "\n\n";
		cout << "8 - ��������� �� �������� ��������� ������� �������������\n";
		cout << "9 - ��������� �� �������� ������������� ������ �����\n";
		cout << "10 - ��������� �� �������� ��������� ������ ���������\n";
		cout << "11 - ��������� �� �������� ������������� ������� ���������\n";
		cout << "\n\n";
		cout << "12 - ��������� ����� � �������\n";
		cout << "13 - ��������� ����� � ������\n";
		cout << "0 - �����\n";
		cout << ">> ";

		cin >> c;
		switch (c)
		{
		case 1:ob->MatrixAdjCreate(temp);
			break;
		case 2:ob->MatrixInchiCreate(temp);
			break;
		case 3:ob->SpisokReberCreate(temp);
			break;
		case 4:ob->SpisokSmejCreate(temp);
			break;
		case 5:

			//--------------------��������������--------------------------------
#ifdef ORIENT
			ob->MatrixAdjReadFile("DataNO.txt", temp);
#endif // ORIENT

			//--------------------�� ��������������------------------------------
#ifdef NEORIENT
			ob->MatrixAdjReadFile("DataNO.txt", temp);
#endif // NEORIENT

			ob->PrintMatrixAdj();
			ob->MatrixAdjToMatrixInchi(temp);
			ob->MatrixAdjToSpisokSmej();
			ob->MatrixInchiToSpisokReber(temp);
			break;
		case 6:
			ob->PrintMatrixAdj();
			ob->PrintMatrixInchi();
			ob->PrintSpisokReber();
			ob->PrintSpisokSmej();
			break;
		case 7:
			//--------------------��������������--------------------------------
#ifdef ORIENT
			ob->writeFile("Data.txt");
#endif // ORIENT

			//--------------------�� ��������������------------------------------
#ifdef NEORIENT
			ob->writeFile("DataNO.txt");
#endif // NEORIENT

			break;
		case 8:ob->MatrixAdjToMatrixInchi(temp);
			break;
		case 9:ob->MatrixAdjToSpisokSmej();
			break;
		case 10:ob->MatrixInchiToSpisokReber(temp);
			break;
		case 11:ob->MatrixInchiToMatrixAdj(temp);
			break;
		case 12:
			//cout << 0 << endl; 
			ob->DFS(0, b);
			for (int i = 0; i < N; i++)
			{
				b[i] = 0;
			}
			//cout << 5 << endl;


			break;
		case 13:
			 ob->BFS(0, b);
			for (int i = 0; i < N; i++)
			{
				b[i] = 0;
			}
			
			break;
		case 0:
			return 0;
		default: break;
		}
	}
	return 0;
}
