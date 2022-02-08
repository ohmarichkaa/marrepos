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
		cout << "1 - заполнить матрицу смежности вручную\n";
		cout << "2 - заполнить матрицу инцидентности вручную\n";
		cout << "3 - заполнить список ребер вручную\n";
		cout << "4 - заполнить список смежности вручную\n";
		cout << "5 - заполнить все виды хранения графа автоматически\n";
		cout << "\n\n";
		cout << "6 - вывести все виды хранения графа на екран\n";
		cout << "7 - записать все виды хранения графа в файл\n";
		cout << "\n\n";
		cout << "8 - построить за матрицей смежности матрицу инцидентности\n";
		cout << "9 - построить за матрицей инцидентности список ребер\n";
		cout << "10 - построить за матрицей смежности список смежности\n";
		cout << "11 - построить за матрицей инцидентности матрицу смежности\n";
		cout << "\n\n";
		cout << "12 - выполнить обход в глубину\n";
		cout << "13 - выполнить обход в ширину\n";
		cout << "0 - выход\n";
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

			//--------------------Ориентированый--------------------------------
#ifdef ORIENT
			ob->MatrixAdjReadFile("DataNO.txt", temp);
#endif // ORIENT

			//--------------------Не ориентированый------------------------------
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
			//--------------------Ориентированый--------------------------------
#ifdef ORIENT
			ob->writeFile("Data.txt");
#endif // ORIENT

			//--------------------Не ориентированый------------------------------
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
